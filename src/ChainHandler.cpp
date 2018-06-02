#include <iostream>
#include "../header/ChainHandler.h"

using namespace std;

ChainHandler::ChainHandler(bool isDone) : isDone(isDone) {}

bool ChainHandler::getIsDone() const {
    return isDone;
}

void ChainHandler::setIsDone(bool isDone) {
    ChainHandler::isDone = isDone;
}

template<typename T, typename K, typename H>
void ChainHandler::execute(T &permanent, ResultMsg<K> &resultMsg, H &&parameter) {
    resultMsg.setData(resultMsg.getData() + parameter);
    cout << permanent << resultMsg.getData() << endl;
}

template<typename T, typename K, typename H>
bool ChainHandler::whetherExecute(T &permanent, ResultMsg<K> &resultMsg, H &&parameter) {
    return true;
}
