### vuex几个核心及组件使用
state:全局数据 this.$store.state.
getter:基于state修改为新数据 this.$store.getter.
mutation:同步修改数据 创建修改方法 this.$store.commit()
action:异步修改数据 function(context(上下文this指向),payload(挂载参数))---可封装为promise对象
this.$store.dispatch