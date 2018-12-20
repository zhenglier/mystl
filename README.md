# mystl
这是小蒟蒻zhenglier写的一个类似stl的东西

使用方法：

将自己的cpp文件与mystl.h文件放进同一个文件夹

在自己的cpp文件的头文件中写上

```cpp
#include "stl.h"
```

这里的头文件必须用""括起来。

如有错误或建议，请联系邮箱3080529100@qq.com



现在支持：

vector:

- push_back(T val)
- pop_back()
- iterator
- begin()
- end()
- insert(iterator pos,T val,int sum=1)
- erase(iterator pos,int sum)
- erase(iterator begin,iterator end)



iostream:

- cin>>T val
- cout<<T val
- 支持类型：int,unsigned int,long long,unsigned long long,float,double,char



sort:

- sort(T* a,T* b);
- sort(T* a,T* b,cmp)
- cmp支持greater,less,equal_to,not_equal_to,greater_equal,less_equal




queue:

- push(T val)
- pop()
- front()