class Solution {
public:
    std::vector<std::vector<std::string>> groupAnagrams(std::vector<std::string>& strs) {
        std::unordered_map<std::string, std::vector<std::string>> mp;
        
        for (const std::string& s : strs) {
            std::string key = s;
            std::sort(key.begin(), key.end()); // Sort characters to form the signature
            mp[key].push_back(s);             // Group the original string
        }
        
        std::vector<std::vector<std::string>> result;
        for (auto& pair : mp) {
            result.push_back(pair.second);
        }
        
        return result;
    }
};
