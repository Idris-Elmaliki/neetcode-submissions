class Solution {
public:
    std::string encode(std::vector<std::string>& strs) {
     // current string encoded 
        std::stringstream cse; 
        
        for(const auto& str : strs) {
            for(int i = 0; i < str.size(); i++) {
                int asciiIndex = static_cast<int>(str[i]);
                cse << asciiIndex; // convert the ascii char to its ascii num!
                cse << ',';  
            }
            cse << (1, ' '); 
        }

        return cse.str(); 
    }  

    std::vector<std::string> decode(std::string s) {
        std::vector<std::string> vec;

        std::cout << s << "\n"; 

        std::string cstring = ""; 
        std::string current = ""; 

        // what we need to do is take the chars (nums) and convert it back to its ascii value 
        for(const char& c : s) { 
            if(c == ',') { 
                int asciiIndex = std::stoi(cstring);
                current.append(1, char(asciiIndex)); 
                
                std::cout << "Current: " << current << '\n'; 
                cstring = ""; 
            }
            else if(c == ' ') {
                // over here!
                vec.emplace_back(current); 
                current = "";  
            }
            else {
                cstring.append(1, c); 
            }
        }

        return vec; 
    }
};
