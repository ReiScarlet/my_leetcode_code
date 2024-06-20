#include <iostream>
#include <memory>
#include <unordered_map>

class CacheNode {
 public:
  int key;
  int value;
  CacheNode *next;
  CacheNode *prev;

  CacheNode(int k = 0, int v = 0)
      : key(k), value(v), next(nullptr), prev(nullptr) {}
};

class LRUCache {
 private:
  void removeCacheNode(CacheNode *node) {
    if (node->prev != nullptr) {
      node->prev->next = node->next;
    } else {
      head = node->next;
    }

    if (node->next != nullptr) {
      node->next->prev = node->prev;
    } else {
      tail = node->prev;
    }
  }

  void pushFrontCacheNode(CacheNode *node) {
    node->next = head;
    node->prev = nullptr;
    if (head != nullptr) {
      head->prev = node;
    }
    head = node;
    if (tail == nullptr) {
      tail = head;
    }
  }

  void debug() {
    std::cout << "debug: ";
    CacheNode *cur = head;
    while (cur) {
      std::cout << "key[" << cur->key << "]:value[" << cur->value << "] ";
      cur = cur->next;
    }
    if (tail) {
      std::cout << "tail[" << tail->key << "]";
    }
    std::cout << std::endl;
  }

 public:
  LRUCache(int capacity) {
    size = capacity;
    head = nullptr;
    tail = nullptr;
  }

  int get(int key) {
    auto iter = cacheMap.find(key);
    if (iter == cacheMap.end()) {
      return -1;
    }
    CacheNode *node = iter->second;
    removeCacheNode(node);
    pushFrontCacheNode(node);
    // debug();
    return node->value;
  }

  void put(int key, int value) {
    auto iter = cacheMap.find(key);
    if (iter != cacheMap.end()) {
      CacheNode *node = iter->second;
      node->value = value;
      removeCacheNode(node);
      pushFrontCacheNode(node);
    } else {
      CacheNode *newNode = new CacheNode(key, value);
      if (cacheMap.size() >= size) {
        auto tailIter = cacheMap.find(tail->key);
        cacheMap.erase(tailIter);
        removeCacheNode(tail);
      }
      pushFrontCacheNode(newNode);
      cacheMap[key] = newNode;
    }
    // debug();
  }

 private:
  int size;
  CacheNode *head, *tail;
  std::unordered_map<int, CacheNode *> cacheMap;
};

int main() {
  auto cache = std::make_shared<LRUCache>(2);
  cache->put(1, 1);
  cache->put(2, 2);
  std::cout << cache->get(1) << std::endl;
  cache->put(3, 3);
  std::cout << cache->get(2) << std::endl;
  cache->put(4, 4);
  std::cout << cache->get(1) << std::endl;
  std::cout << cache->get(3) << std::endl;
  std::cout << cache->get(4) << std::endl;
  return 0;
}