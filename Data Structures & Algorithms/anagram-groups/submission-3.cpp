class Solution {
public:
 
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        char alphabet[26];  

        for(int i = 0; i < sizeof(alphabet) / sizeof(char); i++) {
            alphabet[i] = char(i+97); 
        }
        
        std::unordered_map<std::string, std::vector<std::string>> map; 

        for(auto str : strs) {
            int arr[26] = {}; 
             
            for(int i = 0; i < str.size(); i++) {
                int index = str[i] - 'a';
                if(index >= 0 && index < 26) {
                    ++arr[index]; 
                }
                else {
                    std::cout << "Not a lowercase letter!\n";
                    return {{""}};  
                }
            }

            std::string current;
            for(int i = 0; i < (sizeof(arr) / sizeof(int)); i++) {
                if(arr[i] > 0) {
                    current.append(arr[i], alphabet[i]); 
                }
            }

            map[current].emplace_back(str);
        }

        std::vector<std::vector<std::string>> vec;
        vec.reserve(map.size()); 

        for(auto& data : map) {
            vec.emplace_back(data.second); 
        }

        return vec; 
    }
};