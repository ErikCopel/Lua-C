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
  lua_State* L = luaL_newstate();

  // load Lua libraries
  luaL_openlibs(L);

  // load Lua script
  if (luaL_loadfile(L, "main.lua")) 
  {
    std::cerr << "Falha ao carregar o script!";
  }
  // Open c functions to Lua
  luaopen_sum(L);

  lua_pcall(L, 0, 0, 0);
 

  lua_close(L);
  return 0;
}
