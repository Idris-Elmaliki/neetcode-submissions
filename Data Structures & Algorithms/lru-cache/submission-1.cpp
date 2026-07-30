class LRUCache {
    std::list<std::pair<int, int>> m_list; 
    std::unordered_map<int, std::list<std::pair<int, int>>::iterator> m_map; 
    int m_capacity; 

public:
    LRUCache(const int& capacity) 
    : m_capacity(capacity) 
    {}
    
    int get(const int& key) {
        if(m_map.find(key) != m_map.end()) {
            auto it = m_map[key];
            m_list.splice(m_list.begin(), m_list, it); 
            
            return (*m_map[key]).second; 
        }

        return -1; 
    }
    
    void put(const int& key, const int& value) {
        if(m_map.find(key) == m_map.end()) {
            m_list.emplace_front(std::make_pair(key, value)); 
        
            if(m_list.size() > m_capacity) {
                m_map.erase(m_list.back().first); 
                m_list.pop_back(); 
            }
            
            m_map.insert({key, m_list.begin()});    
        }
        else {
            auto it = m_map[key];
            m_list.splice(m_list.begin(), m_list, it); 
            (*m_map[key]).second = value; 
        }
    }
};
