
// Requires that left and right subtrees obey the heap structure
// Parent node will float down
template<typename TYPE, typename COMP>
void binary_heap<TYPE, COMP>::heapify(int node)
{
  int left = 2 * node + 1;
  int right = 2 * node + 2;
  int size = data.size();
  int smallest;
  if (left < size && this->compare(data[node], data[left]))
  {
    smallest = left;
  }
  else
  {
    smallest = node;
  }
  if (right < size && this->compare(data[smallest], data[right]))
  {
    smallest = right;
  }
  if (smallest != node)
  {
    TYPE temp = data[smallest];
    data[smallest] = data[node];
    data[node] = temp;
    heapify(smallest);
  }
}

template<typename TYPE, typename COMP>
void binary_heap<TYPE, COMP>::make_heap()
{
  //Your code.
  int node = data.size() / 2 - 1;
  for (int i = node; i >= 0; i--)
  {
    heapify(i);
  }
}
