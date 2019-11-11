#include <iostream>
#include <cassert>

class DoubleLink
{
  private:
    struct BaseNode
    {
        BaseNode() : next(nullptr), prev(nullptr) {};
        virtual ~BaseNode() = default;
        BaseNode* next;
        BaseNode* prev;
    };

    struct DataNode : public BaseNode
    {
        DataNode(int input) : data(input) {};
        int data;
    };
    BaseNode* sentinel;
    size_t m_size;

  public:
    // Default ctor
    DoubleLink() : sentinel(new BaseNode()), m_size(0)
    {
      sentinel->next = sentinel;
      sentinel->prev = sentinel;
    }

    // Copy ctor
    DoubleLink(DoubleLink &in) : sentinel(new BaseNode()), m_size(0)
    {
      sentinel->next = sentinel;
      sentinel->prev = sentinel;

      for (auto it = in.begin(); it != in.end(); ++it)
      {
        this->push_back(*it);
      }
    }

    // Copy assgn op
    DoubleLink& operator=(DoubleLink &in)
    {
      // Self assignment
      if (this == &in)
      {
        return *this;
      }

      // Delete the old list
      if (size() != 0)
      {
        BaseNode* curr_node = sentinel->next;
        BaseNode* delete_node = curr_node;
        while (curr_node != sentinel)
        {
          delete_node = curr_node;
          curr_node = curr_node->next;
          delete delete_node;
        }
        sentinel->next = sentinel;
        sentinel->prev = sentinel;
        m_size = 0;
      }

      for (auto it = in.begin(); it != in.end(); ++it)
      {
        this->push_back(*it);
      }
      return *this;
    }

    ~DoubleLink()
    {
      BaseNode* curr_node = sentinel->next;
      BaseNode* delete_node = curr_node;
      while (curr_node != sentinel)
      {
        delete_node = curr_node;
        curr_node = curr_node->next;
        delete delete_node;
      }
      delete sentinel;
    }

    class Iterator
    {
      public:
        Iterator() = delete;
        Iterator(DataNode* node)
        {
          target = node;
        }
        Iterator(const Iterator&) = default;
        Iterator& operator=(const Iterator&) = default;
        ~Iterator() = default;
        Iterator &operator++()
        {
            target = dynamic_cast<DataNode*>(target->next);
            return *this;
        }

        // Postincrement
        Iterator operator++(int)
        {
            DataNode* old = target;
            target = dynamic_cast<DataNode*>(target->next);
            return Iterator(old);
        }

        // Predecrement
        Iterator &operator--()
        {
            target = dynamic_cast<DataNode*>(target->prev);
            return *this;
        }

        // Postdecrement
        Iterator operator--(int)
        {
            DataNode* old = target;
            target = dynamic_cast<DataNode*>(target->prev);
            return Iterator(old);
        }

        int &operator*()
        {
            return target->data;
        }

        int *operator->()
        {
            return &target->data;
        }

        bool operator!=(const Iterator &rh)
        {
            return !(this->target == rh.target);
        }

        bool operator==(const Iterator &rh)
        {
            return this->target == rh.target;
        }
        
      private:
        DataNode* target;
    };

    Iterator begin()
    {
      return Iterator(dynamic_cast<DataNode*>(sentinel->next));
    }

    Iterator end()
    {
      return Iterator(dynamic_cast<DataNode*>(sentinel));
    }

    bool empty()
    {
      return m_size == 0;
    }

    size_t size()
    {
      return m_size;
    }

    // Push a new node at the end of the list
    void push_back(int input)
    {
      DataNode* new_node = new DataNode(input);

      new_node->next = sentinel;
      new_node->prev = sentinel->prev;
      sentinel->prev->next = new_node;
      sentinel->prev = new_node;
      ++m_size;
    }

    // Pop a node at the end of the list
    void pop_back()
    {
      if (m_size == 0)
      {
        return;
      }
      delete sentinel->prev;
      sentinel->prev->prev->next = sentinel;
      sentinel->prev = sentinel->prev->prev;
      --m_size;
    }

    // Push a node at the front of the list
    void push_front(int input)
    {
      DataNode* new_node = new DataNode(input);

      new_node->next = sentinel->next;
      new_node->prev = sentinel;
      sentinel->next->prev = new_node;
      sentinel->next = new_node;
      ++m_size;
    }

    void pop_front()
    {
      if (m_size == 0)
      {
        return;
      }
      delete sentinel->next;
      sentinel->next->next->prev = sentinel;
      sentinel->next = sentinel->next->next;
      --m_size;
    }

    void insert()
    {

    }

    void clear()
    {
      BaseNode* curr_node = sentinel->next;
      BaseNode* delete_node = curr_node;
      while (curr_node != sentinel)
      {
        delete_node = curr_node;
        curr_node = curr_node->next;
        delete delete_node;
      }
      sentinel->next = sentinel;
      sentinel->prev = sentinel;
      m_size = 0;
    }

    Iterator find(int search_data)
    {
      for (auto it = begin(); it != end(); ++it)
      {
        if (search_data == *it)
        {
          return it;
        }
      }
      return end();
    }


};

int main()
{


  DoubleLink list;
  assert(list.size() == 0);
  std::cout << "Empty list pass\n";

  list.push_back(1);
  assert(list.size() == 1);

  auto iter = list.begin();
  
  assert(*iter == 1);
  list.push_back(2);
  list.push_back(3);
  list.push_back(4);
  assert(list.size() == 4);
  iter++;
  assert(*iter == 2);
  iter++;
  assert(*iter == 3);
  iter++;
  assert(*iter == 4);
  std::cout << "Push back pass\n";

  list.push_front(5);
  list.push_front(6);
  assert(list.size() == 6);
  auto iter2 = list.begin();
  assert(*iter2 == 6);
  ++iter2;
  assert(*iter2 == 5);
  ++iter2;
  assert(*iter2 == 1);
  std::cout << "Push front pass\n";

  list.pop_front();
  assert(list.size() == 5);
  auto iter3 = list.begin();
  assert(*iter3 == 5);
  ++iter3;
  assert(*iter3 == 1);
  std::cout << "Pop front pass\n";

  list.pop_back();
  ++iter3;
  ++iter3;
  ++iter3;
  assert(iter3 == list.end());
  std::cout << "Pop back pass\n";

  list.clear();
  assert(list.size() == 0);
  assert(list.begin() == list.end());
  std::cout << "Clear pass\n";

  {
  DoubleLink list2;
  list2.push_back(1);
  list2.push_back(2);
  list2.push_back(3);
  list2.push_back(4);
  DoubleLink list3(list2);
  auto iter4 = list3.begin();

  assert(list3.size() == 4);
  assert(*iter4 == 1);
  iter4++;
  assert(*iter4 == 2);
  iter4++;
  assert(*iter4 == 3);
  iter4++;
  assert(*iter4 == 4);
  std::cout << "Copy ctor pass\n";
  }

  DoubleLink list2;
  list2.push_back(1);
  list2.push_back(2);
  list2.push_back(3);
  list2.push_back(4);
  DoubleLink list3;
  list3 = list2;
  auto iter4 = list3.begin();

  assert(list3.size() == 4);
  assert(*iter4 == 1);
  iter4++;
  assert(*iter4 == 2);
  iter4++;
  assert(*iter4 == 3);
  iter4++;
  assert(*iter4 == 4);

  std::cout << "Copy assgn op pass\n";




  return 0;
}