//
// Created by Frank on 18/6/1.
//

#ifndef SERIALCHAIN_RESULTMSG_H
#define SERIALCHAIN_RESULTMSG_H

#include <list>
#include <string>

using namespace std;

template<typename T>
class ResultMsg {

private:
    bool status;
    const string msg;
    T data;

public:

    ResultMsg() = default;

    ResultMsg(bool status, const string &msg, T data);

    bool isStatus() const;

    void setStatus(bool status);

    const string &getMsg() const;

    T getData() const;

    void setData(T data);

};


#endif //SERIALCHAIN_RESULTMSG_H
