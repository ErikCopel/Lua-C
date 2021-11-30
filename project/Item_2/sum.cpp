#include "lua.hpp"
#include <iostream>

int sum (lua_State *L) {
    //check and fetch the arguments
    double arg1 = luaL_checknumber (L, 1);
    double arg2 = luaL_checknumber (L, 2);

    //push the results
    lua_pushnumber(L, arg1 + arg2);

    //return number of results
    return 1;
}

int luaopen_sum(lua_State *L) {
    // Register sum function
    lua_pushcfunction(L, sum);
    lua_setglobal(L, "sum");

    return 0;
}

int main(int argc, char const *argv[])
{
  printf("Begin...");
  lua_State *L = lua_open();
  int r = luaL_dofile(L, "main.lua");  
  
  lua_call(L, 0, 1);


  system("pause");
  lua_close(L);
  return 0;
}
