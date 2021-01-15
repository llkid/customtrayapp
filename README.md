# customtrayapp
自定义托盘（美化界面）

测试环境：
  vs2019 + msvc2017 32bit + qt插件 + qt5.14.2
  
实现一个简单的托盘自定义菜单，使用 QWidgetAction 代替 QAction，使用

void setDefaultWidget(QWidget *widget);

该方法设置一个自定义布局，可以实现更丰富的效果
待实现，在点击菜单的子项后，该菜单同时保持不消失。
