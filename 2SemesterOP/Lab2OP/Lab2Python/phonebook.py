import datetime

class PhoneBook:  #клас телефоної книги, який містить атрибути,що описують потрібні нам дані дзвінка(дата,час початку,час кінця)
    def __init__(self, date_call:datetime, time_start: datetime, time_end: datetime):
        self.date_call = date_call
        self.time_start = time_start
        self.time_end = time_end

    def __str__(self):                 #метод переведення атрибутів класу у рядок для запису у файл
        return (f"{self.date_call} {self.time_start}-{self.time_end}")
