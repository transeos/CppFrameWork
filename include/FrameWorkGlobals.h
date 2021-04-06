// -*- C++ -*-
//
// WARRANTY:
// Use all material in this file at your own risk.
//
// Created by Hiranmoy Basak on 06/04/21.
//

#pragma once

#include <bits/stdc++.h>

// global variables
#ifdef DEFINE_FRAMEWORK_GLOBALS
#undef GLOBAL_FRAMEWORK
#define GLOBAL_FRAMEWORK(type_var, initial_value) type_var = initial_value
#else
#undef GLOBAL_FRAMEWORK
#define GLOBAL_FRAMEWORK(type_var, initial_value) extern type_var
#endif

GLOBAL_FRAMEWORK(bool g_framework_global_test, true);
