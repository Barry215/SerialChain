#ifndef SERIALCHAIN_CHAINLIST_H
#define SERIALCHAIN_CHAINLIST_H

#include <list>
#include "ChainHandler.h"
#include "ResultMsg.h"

using namespace std;


template<typename T, typename K>
class ChainList {
private:
    T permanent;

    ResultMsg<K> resultMsg;

    list<ChainHandler> handlers;

public:

    ChainList(T permanent, const ResultMsg<K> &resultMsg, const list<ChainHandler, allocator<ChainHandler>> &handlers);

    void start();

    template<typename T>
    void start(T &&arg);

    template<typename T, typename... Args>
    void start(T &&arg, Args &&... parameters);

    T getPermanent() const;

    void setPermanent(T permanent);

    const list<ChainHandler> &getHandlers() const;

    void setHandlers(const list<ChainHandler> &handlers);

    const ResultMsg<K> &getResultMsg() const;

    void setResultMsg(const ResultMsg<K> &resultMsg);

};


#endif //SERIALCHAIN_CHAINLIST_H
