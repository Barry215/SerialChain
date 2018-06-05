//
// Created by Frank on 18/6/5.
//

#include <iostream>
#include "../header/StudentService.h"
using namespace std;


void StudentService::execute(string &permanent, ResultMsg<string> &resultMsg, string &&parameter) {
    cout<< "永久参数:" << permanent <<endl;

    resultMsg = ResultMsg<string>(true, "返回值提示", "返回值:"+parameter);
    cout<< "返回值:" << parameter <<endl;

}

bool StudentService::whetherExecute(string &permanent, ResultMsg<string> &resultMsg, string &&parameter) {
    return true;
}
