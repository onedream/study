class Student :
    def __init__(self,name,student_id)->None:
        self.name=name 
        self.student_id=student_id
        self.grades ={"语文": 0,"数学": 0,"英语": 0 }
    def set_grade(self,course,grade):
        if course in self.grades:
            self.grades[course]=grade
    def print_grade(self):
        print(f"学生:{self.name}\n学号({self.student_id})的成绩为:")
        for course in self.grades:
            print(f"{course}:{self.grades[course]}分") 



chen= Student("小陈","10039")
chen.set_grade("语文",100)
chen.set_grade("数学",100)
chen.set_grade("英语",100)
zeng= Student("小曾","10033")
zeng.set_grade("语文",89)
zeng.set_grade("数学",119)
zeng.set_grade("英语",139)
print(chen.name)
chen.print_grade()
print(zeng.name)
zeng.print_grade()

class Employee :
    def __init__(self,id,name) :
        self.name=name
        self.id=id
    def print_info (self):
        print(f"员工名字:{self.name},员工:{self.id}")
class Fulltime_employee (Employee) :
    def __init__(self, id, name,month_salary):
        super().__init__(id, name)
        self.month_salary = month_salary
    def calculate_monthly_pay(self):
        return self.month_salary
class Parttime_employee (Employee):
    def __init__(self, id, name,daily_salary,work_days):
        super().__init__(id, name)
        self.daily_salary = daily_salary
        self.work_days = work_days
    def calculate_monthly_pay(self):
        return self.daily_salary * self.work_days

W = Fulltime_employee = ("1323","w",23422)
F = Parttime_employee = ("3244","f",32434)
D = Employee=("3243","d")

print(w.calculate_monthly_pay())
