// -*- C++ -*-
//
// WARRANTY:
// Use all material in this file at your own risk.
//
// Created by Hiranmoy Basak on 07/04/21.
//

#pragma once

#include <bits/stdc++.h>

#include <cassandra.h>

class CassServer {
 public:
  CassServer(const std::string& key_space_name);
  ~CassServer();

  CassError executeQuery(const char* query, const bool verbose = true);
  void printError(CassFuture* future);

 private:
  // key space name
  std::string key_space_;

  CassSession* session_;
  CassCluster* cluster_;

  void createCluster(const char* hosts, const int32_t port);
  CassError connectSession();
};
