// -*- C++ -*-
//
// WARRANTY:
// Use all material in this file at your own risk.
//
// Created by Hiranmoy Basak on 06/04/21.
//

#include "FrameWork.h"

// initialize global variables
#define DEFINE_FRAMEWORK_GLOBALS
#include "FrameWorkGlobals.h"

using std::cout;
using std::endl;
using std::string;

namespace FrameWork {
bool CheckFrameWorkBuild() {
  try {
    // json
    json j_obj;
    j_obj["pi"] = 3.1416;
    cout << j_obj << endl;

    json j_obj2 = "{ \"happy\": true, \"pi\": 3.141 }"_json;
    cout << j_obj2 << endl;

    const string& json_string = "{ \"sad\": false, \"pi\": 3.141 }";
    json j_obj3 = json::parse(json_string);
    cout << j_obj3 << endl;

    // Cassandra
    g_cass_server.reset(new CassServer("testframework"));
  } catch (...) {
    cout << "Exception in CheckFrameWorkBuild" << endl;
    return false;
  }

  return true;
}

bool CheckFrameWorkTcp(const int32_t port) {
  tcp::server tcp_server(port);

  tcp_server.OnMessage(PrintTcpMsg);

  int32_t result = tcp_server.Listen();

  if (result != 0) {
    cout << "Faild to start server !" << endl;
    return false;
  }

  return true;
}

// ======================== utils ===========================================
bool ConnectToCassadraDb(const string& key_space) {
  g_cass_server.reset(new CassServer(key_space));
  if (!g_cass_server->IsConnected()) {
    return false;
  }
  return true;
}

CassError ExecuteQuery(const char* query, const bool verbose) {
  return g_cass_server->ExecuteQuery(query, verbose);
}

void PrintTcpMsg(Node* nd, string msg) {
  cout << nd->ip << " : " << msg << std::endl;
}

void LaunchTcpServer(const int32_t port, decltype(PrintTcpMsg) clientMsgCallBack) {
  tcp::server tcp_server(port);

  tcp_server.OnMessage(clientMsgCallBack);

  int32_t result = tcp_server.Listen();

  if (result != 0) {
    cout << "Faild to start server !" << endl;
    return;
  }
}
} // namespace FrameWork
