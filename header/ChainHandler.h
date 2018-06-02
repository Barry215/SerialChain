//
// Created by Frank on 18/5/7.
//

#ifndef SERIALCHAIN_CHAINHANDLER_H
#define SERIALCHAIN_CHAINHANDLER_H

#include "ResultMsg.h"


class ChainHandler {
private:
    bool isDone = false;

public:

    ChainHandler() = default;

    ChainHandler(bool isDone);

    template<typename T, typename K, typename H>
    void execute(T &permanent, ResultMsg<K> &resultMsg, H &&parameter);

    template<typename T, typename K, typename H>
    bool whetherExecute(T &permanent, ResultMsg<K> &resultMsg, H &&parameter);

//    virtual ~ChainHandler() = default;

    bool getIsDone() const;

    void setIsDone(bool isDone);
};

#endif //SERIALCHAIN_CHAINHANDLER_H