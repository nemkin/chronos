timeslot(monday-8-10).
timeslot(monday-10-12).
timeslot(monday-12-14).
timeslot(monday-14-16).
timeslot(monday-16-18).

timeslot(tuesday-8-10).
timeslot(tuesday-10-12).
timeslot(tuesday-12-14).
timeslot(tuesday-14-16).
timeslot(tuesday-16-18).

timeslot(wednesday-8-10).
timeslot(wednesday-10-12).
timeslot(wednesday-12-14).
timeslot(wednesday-14-16).
timeslot(wednesday-16-18).

timeslot(thursday-8-10).
timeslot(thursday-10-12).
timeslot(thursday-12-14).
timeslot(thursday-14-16).
timeslot(thursday-16-18).

timeslot(friday-8-10).
timeslot(friday-10-12).
timeslot(friday-12-14).
timeslot(friday-14-16).
timeslot(friday-16-18).

building(A).
building(CH).
building(E).
building(H).
building(I).
building(K).
building(Q).
building(R).
building(T).
building(V1).
building(F).

class_type(lecture).
class_type(practice).
class_type(laboratory).

semester(1).
semester(2).
semester(3).
semester(4).
semester(5).
semester(6).
semester(7).

room(IB028, XL, I, lecture).
room(Q-I, XL, Q, lecture).
room(E1B, XL, E, lecture).
room(IB027, L, I, lecture).
room(IB026, L, I, lecture).
room(IB025, L, I, lecture).
room(IE007, L, I, lecture).
room(E1C, L, I, lecture).
room(QBF08, M, Q, practice).
room(QBF09, M, Q, practice).
room(QBF12, M, Q, practice).
room(E401, S, E, practice).
room(E402, S, E, practice).
room(E403, S, E, practice).
room(E404, S, E, practice).
room(E405, S, E, practice).
room(E406, S, E, practice).
room(E407, S, E, practice).
room(IB134, S, I, practice).
room(IB138, S, I, practice).
room(IB139, S, I, practice).
room(IB140, S, I, practice).
room(IB141, S, I, practice).
room(IB142, S, I, practice).
room(IB144, S, I, practice).
room(IB145, S, I, practice).
room(IB146, S, I, practice).
room(IB147, S, I, practice).
room(IB310, S, I, practice).
room(IB413, S, I, practice).
room(QA240, S, Q, practice).
room(QAF14, S, Q, practice).
room(QB105, S, Q, practice).
room(QB311, S, Q, practice).
room(QB331, S, Q, practice).
room(R4A, S, R, laboratory).
room(R4B, S, R, laboratory).
room(R4C, S, R, laboratory).
room(R4I, S, R, laboratory).
room(R4J, S, R, laboratory).
room(R4K, S, R, laboratory).
room(R4L, S, R, laboratory).
room(R4M, S, R, laboratory).
room(R4N, S, R, laboratory).
room(R4O, S, R, laboratory).
room(R4P, S, R, laboratory).

department(AUT).
department(ETT).
department(EET).
department(HIT).
department(IIT).
department(MIT).
department(SZIT).
department(HVT).
department(TMIT).
department(VET).
department(BTK).
department(MAT).
department(FIZ).

#Course(name, year, department)
course(Analizis-1, 1, MAT).
course(A-programozas-alapjai-1, 1, EET).
course(Bevezetes-a-szamitaselmeletbe-1, 1, SZIT).
course(Bevezeto-fizika, 1, FIZ).
course(Bevezeto-matematika, 1, MAT).
course(Digitalis-technika, 1, MIT).
course(Fizika-1, 1, FIZ).
course(Mernok-leszek, 1, BTK).
course(Analizis-2, 2, MAT).
course(A-programozas-alapjai-2, 2, IIT).
course(Bevezetes-a-szamitaselmeletbe-2, 2, SZIT).
course(Fizika-2, 2, FIZ).
course(Rendszermodellezes, 2, MIT).
course(Szamitogep-architekturak, 2, HIT).
course(A-programozas-alapjai-3, 3, IIT).
course(Adatbazisok, 3, TMIT).
course(Kodolastechnika, 3, HIT).
course(Kommunikacios-halozatok-1, 3, HIT).
course(Rendszerelmelet, 3, HVT).
course(Szoftvertechnologia, 3, IIT).
course(Valoszinusegszamitas, 3, SZIT).
course(Algoritmuselmelet, 4, SZIT).
course(Kommunikacios-halozatok-2, 4, TMIT). 
course(Menedzsment-es-vallalkozasgazdasagtan, 4, BTK).
course(Operacios-rendszerek, 4, MIT).
course(Szamitogepes-grafika, 4, IIT).
course(Szoftver-projekt-laboratorium, 4, IIT).
course(Szoftvertechnikak, 4, AUT).
course(IT-eszkozok-technologiaja, 5, EET).
course(Mesterseges-intelligencia, 5, MIT).
course(Mikro-es-makrookonomia, 5, BTK).
course(Mobil-es-webes-szoftverek, 5, AUT).
course(Uzleti-jog, 5, BTK).
course(Informatikai-rendszertervezes, 5, MIT).
course(Ipari-informatika, 5, IIT).
course(Informacios-rendszerek-uzemeltetese, 6, TMIT).
course(IT-biztonsag, 6, HIT).
course(Alkalmazasfejlesztesi-kornyezetek, 6, AUT).
course(Intelligens-elosztott-rendszerek, 6, MIT).
course(Rendszertervezes-laboratorium-1, 6, MIT).
course(Deklarativ-programozas, 7, SZIT).
course(Rendszertervezes-laboratorium-2, 7, MIT).

class(X, courseName, ):-
  course(
