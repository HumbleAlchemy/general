from kivy.app import App
from kivy.uix.floatlayout import FloatLayout
from kivy.uix.gridlayout import GridLayout
from kivy.uix.boxlayout import BoxLayout
from kivy.lang import Builder

Builder.load_string('''
# <GridLayout>
#     canvas.before:
#         BorderImage:
#             border: 10,10,10,10
#             pos: self.pos
#             size: self.size
# 
<RootWidget>
    GridLayout:
        size_hint: .9, .9
        pos_hint: {'center_x':.5, 'center_y':.5}
        rows:1
        Label:
            text: "this is blah"
            text_size: self.width-20,self.height-20
            valign: 'top'
        Label:
            text: "this is more blah"
            text_size: self.width-20,self.height-20
            valign: 'middle'
''')

class RootWidget(BoxLayout):
    pass

class MainApp(App):

    def build(self):
        return RootWidget()

if __name__ == '__main__':
    MainApp().run()

