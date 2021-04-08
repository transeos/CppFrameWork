// -*- C++ -*-
//
// WARRANTY:
// Use all material in this file at your own risk.
//
// Created by Hiranmoy Basak on 07/04/21.
//

#include "CassServer.h"

#include "FrameWorkGlobals.h"

#define CASS_PORT 9042

using std::cout;
using std::endl;

CassServer::CassServer(const std::string& key_space_name) :
  key_space_(key_space_name),
  session_(cass_session_new()),
  cluster_(nullptr) {

  const char* cass_ip = getenv("CASSANDRA_IP");
  g_cassandra_ip = (cass_ip ? cass_ip : "127.0.0.1");

  CreateCluster(g_cassandra_ip.c_str(), CASS_PORT);

  // setting request time out to 10 min (default: 2 sec) to handle large requests
  cass_cluster_set_request_timeout(cluster_, 600000);

  if (ConnectSession() != CASS_OK) {
    cass_cluster_free(cluster_);
    cluster_ = nullptr;

    cass_session_free(session_);
    session_ = nullptr;

    cout << "[Warning] not able to connect to cassanda database\n";
    return;
  }

  std::string key_space_query = "CREATE KEYSPACE IF NOT EXISTS " + key_space_;
  key_space_query = key_space_query + " WITH replication = { 'class': 'SimpleStrategy', 'replication_factor': '1' };";

  ExecuteQuery(key_space_query.c_str());
}

CassServer::~CassServer() {
  if (session_) {
    CassFuture* close_future = cass_session_close(session_);
    cass_future_wait(close_future);
    cass_future_free(close_future);

    cass_cluster_free(cluster_);
    cass_session_free(session_);
  }
}

bool CassServer::IsConnected() const {
  return (cluster_ != nullptr);
}

void CassServer::PrintError(CassFuture* future) {
  const char* message = nullptr;
  size_t message_length;
  cass_future_error_message(future, &message, &message_length);
  cout << "[Warning]Cass_Error: " << message << endl;
}

void CassServer::CreateCluster(const char* hosts, const int32_t port) {
  cluster_ = cass_cluster_new();
  cass_cluster_set_contact_points(cluster_, hosts);
  cass_cluster_set_port(cluster_, port);
}

CassError CassServer::ConnectSession() {
  CassFuture* future = cass_session_connect(session_, cluster_);
  cass_future_wait(future);

  CassError rc = cass_future_error_code(future);
  if (rc != CASS_OK) PrintError(future);

  cass_future_free(future);
  return rc;
}

CassError CassServer::ExecuteQuery(const char* query, const bool verbose) {
  if (verbose) {
   cout << "cql_query = " << query << endl;
  }

  CassStatement* statement = cass_statement_new(query, 0);

  CassFuture* future = cass_session_execute(session_, statement);
  cass_future_wait(future);

  CassError rc = cass_future_error_code(future);
  if (rc != CASS_OK) {
    if (verbose) PrintError(future);
  }

  cass_future_free(future);
  cass_statement_free(statement);
  return rc;
}
