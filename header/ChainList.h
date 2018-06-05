#ifndef SERIALCHAIN_CHAINLIST_H
#define SERIALCHAIN_CHAINLIST_H

#include <list>
#include "ChainHandler.h"
#include "ResultMsg.h"

using namespace std;


template<typename T, typename K, typename Y>
class ChainList {
private:
    T permanent;

    ResultMsg<K> resultMsg;

    list<ChainHandler<T, K, Y>> handlers;

public:

    ChainList(T permanent, const ResultMsg<K> &resultMsg, const list<ChainHandler<T, K, Y>> &handlers);

    void start();

    template<typename H>
    void start(H &&arg);

    template<typename H, typename... Args>
    void start(H &&arg, Args &&... parameters);

    T getPermanent() const;

    void setPermanent(T permanent);

    const list<ChainHandler<T, K, Y>> &getHandlers() const;

    void setHandlers(const list<ChainHandler<T, K, Y>> &handlers);

    const ResultMsg<K> &getResultMsg() const;

    void setResultMsg(const ResultMsg<K> &resultMsg);

};

template<typename T, typename K, typename Y>
void ChainList<T, K, Y>::start() {
    list<ChainHandler<T, K, Y>>::iterator it = handlers.begin();
    bool flag = false;

    while (it != handlers.end()) {
        if (!it->getIsDone()) {
            flag = true;
            if (it->whetherExecute(permanent, resultMsg, NULL)) {
                it->execute(permanent, resultMsg, NULL);
            }
            it->setIsDone(true);
            break;
        }
    }

    if (flag) {
        start();
    }

};

template<typename T, typename K, typename Y>
template<typename H>
void ChainList<T, K, Y>::start(H &&arg) {
    list<ChainHandler<T, K, Y>>::iterator it = handlers.begin();

    while (it != handlers.end()) {
        if (!it->getIsDone()) {

            if (it->whetherExecute(permanent, resultMsg, arg)) {
                it->execute(permanent, resultMsg, arg);
            }
            it->setIsDone(true);
            break;
        }
    }

    start();
};

template<typename T, typename K, typename Y>
template<typename H, typename... Args>
void ChainList<T, K, Y>::start(H &&arg, Args &&... parameters) {
    cout << "剩余可变参的个数:" << sizeof...(parameters) << endl;

    list<ChainHandler<T, K, Y>>::iterator it = handlers.begin();

    while (it != handlers.end()) {
        if (!it->getIsDone()) {

            if (it->whetherExecute(permanent, resultMsg, arg)) {
                it->execute(permanent, resultMsg, arg);
            }
            it->setIsDone(true);
            break;
        }
    }

    start(parameters...);
}


template<typename T, typename K, typename Y>
T ChainList<T, K, Y>::getPermanent() const {
    return permanent;
}

template<typename T, typename K, typename Y>
void ChainList<T, K, Y>::setPermanent(T permanent) {
    ChainList<T, K, Y>::permanent = permanent;
}

template<typename T, typename K, typename Y>
const list<ChainHandler<T, K, Y>> &ChainList<T, K, Y>::getHandlers() const {
    return handlers;
}

template<typename T, typename K, typename Y>
void ChainList<T, K, Y>::setHandlers(const list<ChainHandler<T, K, Y>> &handlers) {
    ChainList<T, K, Y>::handlers = handlers;
}

template<typename T, typename K, typename Y>
const ResultMsg<K> &ChainList<T, K, Y>::getResultMsg() const {
    return resultMsg;
}

template<typename T, typename K, typename Y>
void ChainList<T, K, Y>::setResultMsg(const ResultMsg<K> &resultMsg) {
    ChainList<T, K, Y>::resultMsg = resultMsg;
}

template<typename T, typename K, typename Y>
ChainList<T, K, Y>::ChainList(T permanent, const ResultMsg<K> &resultMsg,
                              const list<ChainHandler<T, K, Y>> &handlers) : permanent(permanent),
                                                                             resultMsg(resultMsg),
                                                                             handlers(handlers) {}


#endif //SERIALCHAIN_CHAINLIST_H
