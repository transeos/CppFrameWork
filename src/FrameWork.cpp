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

using nlohmann::json;

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

    // Cassandra
    g_cass_server.reset(new CassServer("testframework"));
  } catch (...) {
    cout << "Exception in CheckFrameWorkBuild" << endl;
    return false;
  }

  return true;
}

void PrintTcpMsg(Node* nd, string msg) {
  cout << nd->ip <<" : " << msg << std::endl;
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

} // namespace FrameWork
