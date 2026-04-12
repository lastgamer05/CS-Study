Stack
======================

### Stack
 - stack은 선입선출이다. (last in first out)
 - 처음 요소를 찾거나 insert하거나 지우는건 O(1)이다.
 - 그러나 맨 뒤의 요소를 지우는 것은 O(1)
 - 구현한 single_list를 이용해 구현할 수 있는데 생성자와 소멸자는 따로 구현할 필요 없고, empty()와 push()도 그대로 single list꺼를 사용하면 된다.
 - 그러나 top()이나 pop()은 empty인지 확인해줘야 함.


