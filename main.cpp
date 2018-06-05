#include <iostream>
#include <list>
#include <string>
#include "header/ChainList.h"
#include "header/ResultMsg.h"
#include "header/StudentService.h"

using namespace std;

int main() {
    StudentService chain1;
    StudentService chain2;
    StudentService chain3;
    list<ChainHandler> chainHandlerList;
    chainHandlerList.push_back(chain1);
    chainHandlerList.push_back(chain2);
    chainHandlerList.push_back(chain3);

    string permanent = "永久参数";

    ResultMsg<string> resultMsg(false,"提示初始值","");

    ChainList chainList(permanent, resultMsg, chainHandlerList);

    chainList.start("参数1","参数2","参数3");

    return 0;
}