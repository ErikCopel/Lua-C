
#ifdef __cplusplus
  #include "lua.hpp"
#else
  #include "lua.h"
  #include "lualib.h"
  #include "lauxlib.h"
#endif

#ifdef __cplusplus
extern "C"{
#endif

int sum (lua_State *L) {
    //check and fetch the arguments
    double arg1 = luaL_checknumber (L, 1);
    double arg2 = luaL_checknumber (L, 2);

    //push the results
    lua_pushnumber(L, arg1 + arg2);

    //return number of results
    return 1;
}

int summation (lua_State *L) {
    
    int result = 0;

    for (int i=1; i<=lua_gettop(L); i++) {
        result = result + luaL_checknumber(L, i); 
    }

    lua_pushnumber(L, result);

    return 1;
}

int luaopen_sum(lua_State *L) {
    // Register sum function
    lua_pushcfunction(L, sum);
    lua_setglobal(L, "sum");

    // Register summation function
    lua_pushcfunction(L, summation);
    lua_setglobal(L, "summation");
    return 0;
}

#ifdef __cplusplus
}
#endif


