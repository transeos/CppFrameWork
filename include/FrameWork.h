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

namespace FrameWork {
bool CheckFrameWorkBuild();

void PrintTcpMsg(Node* nd, std::string msg);

bool CheckFrameWorkTcp(const int32_t port);
}
