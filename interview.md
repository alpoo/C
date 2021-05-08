### js单线程
同一时间只能做一件事情
保证用户对dom节点的操作是有序的 
防止在同一时间不同用户对dom节点的互斥操作

### 为什么需要异步
如果没有异步
JS代码只能自上而下执行
如果某一行代码执行时间很长
那么就会导致阻塞
导致用户页面卡死现象

### 浏览器渲染页面过程
浏览器GUI图形渲染和JS线程加载互斥
1.根据html文件创建dom树和cssom树
根节点为html标签 标签与树节点一一对应
如遇到js文件 优先加载 会堵塞dom和cssom的构建 
2.将dom树、cssom树合并为渲染树

### 关于浏览器页面渲染问题
link标签不会堵塞DOM解析 但会阻塞页面渲染
script标签会堵塞DOM解析
script若没有加defer/async关键字 会触发页面渲染
这时会等待未下载完的css资源

所以link标签放在头部 script放在body底部
同放在头部时 script放在link上方

### 在script标签添加async/defer关键字
defer能保证多个脚本按照顺序执行
async不能保证按照顺序执行

### 有哪些异步函数
setimeout setInterval

### 迭代器与生成器
迭代器是按需创建的一次性对象 symbol.iterator
生成器的形式是一个函数-拥有在一个函数块内暂停和恢复代码执行的能力 symbol.generator 
原生语言结构会在后台调用提供的可迭代对象的这个工厂函数
迭代器会阻止垃圾回收程序回收可迭代对象

调用生成器函数会生成生成器对象


### 变量提升
在函数[内部]使用var关键字时 会将变量声明提升到函数顶部
函数外部无

### cookie localStorage sessionStorage
cookie
    原生JS document.cookie 
    需自己封装setCookie()、getCookie()方法
    大小有限 且每次请求都会被发送
    需要指定作用域 不可以跨域调用
web storage 
    为本地存储而生
localStorage 会一直保存在本地
sessionStorage 会话结束或退出页面后会被清除

### 创建执行上下文
JS代码执行时 创建执行上下文（预执行）->压入执行栈中
全局执行上下文创建时-函数外部的变量会被放到内存中

执行上下文（执行环境）：包括全局执行环境、函数执行环境。
每个环境包括三部分：变量对象/活动对象、作用域链、this的值

变量对象 var、let声明的变量以及函数
活动对象在函数执行上下文里，调用函数时，创建函数执行上下文，激活活动对象。

### nodejs是用来做什么的
一种javascript的运行环境，能够使得javascript脱离浏览器运行。

### MVVM Model-View-viewModel
Model、view层独立变化和修改 通过viewModel实现双向绑定
Model : 定义数据模型、数据、页面逻辑
View:UI视图 负责数据的展示
viewModel:监听数据改变更新视图 处理用户交互
viewModel负责把Model的数据同步到view展示出来
还负责把view的修改同步回Model
从数据存储读出数据展现在用户界面
从界面读取用户输入写入数据存储
viewmodel就是view对应的model
负责将model对象封装成显示和接受输入的界面数据对象

### MVC model-view-control
M：业务模型 V:用户界面 C：控制器
视图层和业务层分离

#### window对象是global对象的代理

### Vue响应式原理
生成实例时遍历data属性 通过object.defineProperty()方法设置属性 设置setter getter函数

### bind apply call 重新定义this指向
bind返回新函数 apply传参为数组 call逐个传参

### JS执行事件顺序
同步任务
异步任务 eventtable(下载好script脚本后)->进入event queue 宏任务->微任务
promise构造函数同步执行
主线程空闲时才会读取任务队列
先执行微任务在执行宏任务








