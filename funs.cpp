#include "funs.h"
#include "json.hpp"
#include <algorithm>
#include <fstream>
#include <functional>
#include <iostream>
#include <sstream>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;
using json = nlohmann::json;
using json_type = const nlohmann::json_abi_v3_11_2::detail::iteration_proxy_value<nlohmann::json_abi_v3_11_2::detail::iter_impl<nlohmann::json_abi_v3_11_2::json>>;

// 寻找属性值attribute满足compare_的所有实体
vector<string> find_entitys(graph &mp, string attribute, function<bool(string)> compare_) {
    vector<string> ans;
    for (auto kv : mp) {
        if (kv.second.count(attribute) && compare_(kv.second[attribute]))
            ans.emplace_back(kv.first);
    }
    return ans;
}

// 寻找实体中属性值等于attribute_value的属性
string find_attribute(graph &mp, string entity, string attribute_value) {
    for (auto x : mp[entity]) {
        if (x.second.find(attribute_value) != string::npos)
            return x.first;
    }
    return string("none");
}
graph read_hl_data(string fileName) {
    ifstream in(fileName);
    graph mp;
    string line;
    getline(in, line);
    while (getline(in, line)) {
        istringstream sin(line);
        vector<string> fields;
        string tmp;
        while (getline(sin, tmp, ','))
            fields.push_back(tmp);
        mp[fields[2]][fields[1]] = fields[3];
        mp[fields[2]]["家族"] = fields[5];
    }
    return mp;
}
void read_json(graph &mp, json_type &x, json_type &y) {
    if (y.value().is_string())
        mp[x.value()["中文名"]][y.key()] = y.value();
    else if (y.value().is_array())
        mp[x.value()["中文名"]][y.key()] = y.value().dump();
    else if (y.value().is_structured()) {
        auto values = y.value();
        for (auto &z : values.items())
            read_json(mp, x, z);
    }
}
graph read_json_data(string fileName) {
    graph ans;
    ifstream ifs(fileName);
    json jf = json::parse(ifs);

    for (auto &x : jf.items()) {
        auto values = x.value();
        for (auto &y : values.items()) {
            read_json(ans, x, y);
        }
    }
    return ans;
}