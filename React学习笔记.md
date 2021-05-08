### Prop、State是异步更新的
可将setstate（）接受一个函数
```javascript
this.setstate((state,props)=>({
    obj:obj
}))
```

### 原型
函数创建->拥有prototype属性对象
new实例->拥有__proto__指向函数原型对象

__proto__属性可以是另一个函数的实例 -> 拥有__proto__指向上一级函数 原型对象(prototype
最高级构造函数f() object
new出来的对象object 的constructor指向object构造函数

### typescript
限制类型的javascript