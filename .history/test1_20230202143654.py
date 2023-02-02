class Student :
    def __init__(self,name,student_id)->None:
        self.name=name 
        self.student_id=student_id
        self.grades ={"语文": 0,"数学": 0,"英语": 0 }
    def set_grade(self,course,grade):
        if course in self.grades:
            self.grades[course]=grade
    def print_grade(self):
        print(f"学生{self.name}学号:{self.student_id}的成绩为：")
        for course in self.grades:
            print(f"course:{self.grades[course]}分") 



chen= Student("小陈","10039")
chen.set_grade("语文",100)
chen.set_grade("数学",100)
chen.set_grade("英语",100)
zeng= Student("小曾","10033")
zeng.set_grade("语文",89)
zeng.set_grade("数学",119)
zeng.set_grade("英语",139)
print(chen.name)
print(chen.grades)
print(zeng.name)
print(zeng.grades)