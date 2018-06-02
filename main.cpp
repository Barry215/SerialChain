#include <iostream>
#include <list>
#include <string>
#include "header/ChainList.h"
#include "header/ResultMsg.h"

using namespace std;

int main() {
    ChainHandler newChain1;
    ChainHandler newChain2;
    ChainHandler newChain3;
    list<ChainHandler> chainHandlerList;
    chainHandlerList.push_back(newChain1);
    chainHandlerList.push_back(newChain2);
    chainHandlerList.push_back(newChain3);

    string permanent = "data的值为: ";

    ResultMsg<int> resultMsg(false,"初始值",1);

    ChainList chainList(permanent, resultMsg, chainHandlerList);

    chainList.start(10, 20, 30);

    return 0;
}