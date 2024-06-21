#include <list>
#include <memory>
#include <unordered_map>

class LFUCache {
 private:
  class LFUCacheNode {
   public:
    int key;
    int value;
    int freq;

    LFUCacheNode(int k = 0, int v = 0, int f = 0) : key(k), value(v), freq(f) {}
  };

 public:
  LFUCache(int capacity) {
    size = capacity;
    min_freq = 0;
    key_table.clear();
    freq_table.clear();
  }

  int get(int key) {
    if (size == 0) return -1;
    auto iter = key_table.find(key);
    if (iter == key_table.end()) return -1;
    std::list<LFUCacheNode>::iterator node = iter->second;
    int val = node->value, freq = node->freq;
    freq_table[freq].erase(node);
    if (freq_table[freq].size() == 0) {
      freq_table.erase(freq);
      if (min_freq == freq) min_freq += 1;
    }
    freq_table[freq + 1].push_front(LFUCacheNode(key, val, freq + 1));
    key_table[key] = freq_table[freq + 1].begin();
    return val;
  }

  void put(int key, int value) {
    if (size == 0) return;
    auto iter = key_table.find(key);
    if (iter == key_table.end()) {
      if (key_table.size() == size) {
        auto iter2 = freq_table[min_freq].back();
        key_table.erase(iter2.key);
        freq_table[min_freq].pop_back();
        if (freq_table[min_freq].size() == 0) {
          freq_table.erase(min_freq);
        }
      }
      freq_table[1].push_front(LFUCacheNode(key, value, 1));
      key_table[key] = freq_table[1].begin();
      min_freq = 1;
    } else {
      std::list<LFUCacheNode>::iterator node = iter->second;
      int freq = node->freq;
      freq_table[freq].erase(node);
      if (freq_table[freq].size() == 0) {
        freq_table.erase(freq);
        if (min_freq == freq) min_freq += 1;
      }
      freq_table[freq + 1].push_front(LFUCacheNode(key, value, freq + 1));
      key_table[key] = freq_table[freq + 1].begin();
    }
  }

 private:
  int size;
  int min_freq;
  std::unordered_map<int, std::list<LFUCacheNode>::iterator> key_table;
  std::unordered_map<int, std::list<LFUCacheNode>> freq_table;
};