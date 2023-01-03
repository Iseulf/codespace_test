#include "funs.h"
#include <iostream>

int main(int argc, char const *argv[]) {
    using namespace std;
    auto mp = read_json_data("./data/data-json.json");
    // auto vp = find_entitys(mp, "国籍", [](string x) { return x == "中国"; });
    cout << find_attribute(mp, "邓子恢", "陈兰") << endl;
    cout << find_attribute_value(mp, "钱伟长", "妻子") << endl;
    // for (auto s : vp)
    // cout << s << endl;
    return 0;
}
