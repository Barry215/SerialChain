//
// Created by Frank on 18/5/7.
//

#ifndef SERIALCHAIN_CHAINHANDLER_H
#define SERIALCHAIN_CHAINHANDLER_H

#include "ResultMsg.h"


template<typename T, typename K, typename H>
class ChainHandler {
private:
    bool isDone = false;

public:

    ChainHandler() = default;

    ChainHandler(bool isDone);

    virtual void execute(T &permanent, ResultMsg<K> &resultMsg, H &&parameter) = 0;

    virtual bool whetherExecute(T &permanent, ResultMsg<K> &resultMsg, H &&parameter) = 0;

    virtual ~ChainHandler() = default;

    bool getIsDone() const;

    void setIsDone(bool isDone);
};

template<typename T, typename K, typename H>
ChainHandler<T, K, H>::ChainHandler(bool isDone) : isDone(isDone) {}

template<typename T, typename K, typename H>
bool ChainHandler<T, K, H>::getIsDone() const {
    return isDone;
}

template<typename T, typename K, typename H>
void ChainHandler<T, K, H>::setIsDone(bool isDone) {
    ChainHandler::isDone = isDone;
}


#endif //SERIALCHAIN_CHAINHANDLER_H