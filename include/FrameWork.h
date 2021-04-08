// -*- C++ -*-
//
// WARRANTY:
// Use all material in this file at your own risk.
//
// Created by Hiranmoy Basak on 06/04/21.
//

#pragma once

#include <bits/stdc++.h>

#include <nlohmann/json.hpp>
#include <tcp/tcp_server.hpp>

#include "CassServer.h"

using nlohmann::json;

namespace FrameWork {
bool CheckFrameWorkBuild();

bool CheckFrameWorkTcp(const int32_t port);

// utils
bool ConnectToCassadraDb(const std::string& key_space);

CassError ExecuteQuery(const char* query, const bool verbose = false);

void PrintTcpMsg(Node* nd, std::string msg);

void LaunchTcpServer(const int32_t port, decltype(PrintTcpMsg) clientMsgCallBack);
}
