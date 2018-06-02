#include <iostream>
#include <list>
#include <string>
#include "../header/ChainList.h"
#include "../header/ChainHandler.h"
#include "../header/ResultMsg.h"


using namespace std;

template<typename K>
void ChainList::start() {
    list<ChainHandler>::iterator it = this->handlers.begin();
    bool flag = false;

    while (it != this->handlers.end()) {
        if (!it->getIsDone()) {
            flag = true;
            if (it->whetherExecute(this->getPermanent(), this->resultMsg, NULL)) {
                it->execute(this->getPermanent(), this->resultMsg, NULL);
            }
            it->setIsDone(true);
            break;
        }
    }

    if (flag) {
        start();
    }

};

template<typename T, typename K>
void ChainList::start(T &&arg) {
    list<ChainHandler>::iterator it = this->handlers.begin();

    while (it != this->handlers.end()) {
        if (!it->getIsDone()) {

            if (it->whetherExecute(this->getPermanent(), this->resultMsg, arg)) {
                it->execute(this->getPermanent(), this->resultMsg, arg);
            }
            it->setIsDone(true);
            break;
        }
    }

    start();
};

template<typename T, typename K, typename... Args>
void ChainList::start(T &&arg, Args &&... parameters) {
    cout << "可变参的个数:" << sizeof...(parameters) << endl;

    list<ChainHandler>::iterator it = this->handlers.begin();

    while (it != this->handlers.end()) {
        if (!it->getIsDone()) {

            if (it->whetherExecute(this->getPermanent(), this->resultMsg, arg)) {
                it->execute(this->getPermanent(), this->resultMsg, arg);
            }
            it->setIsDone(true);
            break;
        }
    }

    start(parameters...);
}


template<typename T>
T ChainList::getPermanent() const {
    return permanent;
}

template<typename T>
void ChainList::setPermanent(T permanent) {
    ChainList::permanent = permanent;
}

const list<ChainHandler> &ChainList::getHandlers() const {
    return handlers;
}

void ChainList::setHandlers(const list<ChainHandler> &handlers) {
    ChainList::handlers = handlers;
}

template<typename K>
const ResultMsg<K> &ChainList::getResultMsg() const {
    return resultMsg;
}

template<typename K>
void ChainList::setResultMsg(const ResultMsg<K> &resultMsg) {
    ChainList::resultMsg = resultMsg;
}

template<typename T, typename K>
ChainList::ChainList(T permanent, const ResultMsg<K> &resultMsg,
                     const list<ChainHandler, allocator<ChainHandler>> &handlers) : permanent(permanent),
                                                                                    resultMsg(resultMsg),
                                                                                    handlers(handlers) {}



