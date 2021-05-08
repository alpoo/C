### 1.Class绑定

①对象语法

```vue
<div class = "tab"
     v-bind:class="{'active':active,'unactive':!active}">
</div>
```

vm实例中需包括：

```vue
data(){
 return{
	active:true
 }
}
```

渲染结果为 

```vue
<div class="tab active"></div>
```

②数组语法

```vue
<div v-bind:class="[classA,classB]"></div>
```

vm实例中需包括：

```vue
data(){
 return{
	classA:'class-a',
	classB:'class-b'
 }
}
```

渲染结果为

```vue
<div class="class-a class-b"></div>
```

③三元表达式

```vue
<divv-bind:class="[classA,isB?classB:'']"></div>
```

if vm.isB = false  ***=>*** 结果 <div v-bind:class="class-a"><div>

### 2.Style样式绑定

