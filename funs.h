#ifndef _FUNS_H_
#define _FUNS_H_
#include <unordered_map>
#include <functional>
#include <string>
#include <vector>
// 知识图谱数据结构
using graph = std::unordered_map<std::string, std::unordered_map<std::string, std::string>>;
// 寻找实体entity的属性attribute值
inline std::string find_attribute_value(graph &mp, std::string entity, std::string attribute) {
    if (mp.count(entity) && mp[entity].count(attribute))
        return mp[entity][attribute];
    return std::string("none");
}
// -1：entity1.attribute<entity2.attribute 0：entity1.attribute==entity2.attribute
// 1：entity1.attribute>entity2.attribute -2：error
inline int compare_attribute(graph &mp, std::string entity1, std::string entity2, std::string attribute, std::function<int(std::string, std::string)> compare_) {
    if (mp.count(entity1) && mp.count(entity2) && mp[entity1].count(attribute) && mp[entity2].count(attribute))
        return compare_(mp[entity1][attribute], mp[entity2][attribute]);
    return -2;
}
std::vector<std::string> find_entitys(graph &mp, std::string attribute, std::function<bool(std::string)> compare_);
std::string find_attribute(graph &mp, std::string entity, std::string attribute_value);
graph read_hl_data(std::string fileName);
graph read_json_data(std::string fileName);
#endif