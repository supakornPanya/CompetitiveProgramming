data = input() 
dmy, money, roundd, now = data.split()
money = float(money)
roundd = float(roundd)
now = float(now)
d, m, y = map(int, dmy.split("/"))

cnt = 0
while cnt <= roundd - 1:
    if (now  % 12) == m :
        profit = money * ((((cnt % 4 + 1) + 1)/100)/12)
        money += profit
        # print(cnt, now % 12 + 1)
        # print( "money1 : ", round(money,2),  round(profit,2), cnt%4+1+1) 
    else :
        profit = money * (((cnt % 4 + 1)/100)/12)
        money += profit
        # print(cnt, now % 12 + 1)
        # print( "money2 : ", round(money,2),  round(profit,2), cnt%4+1)
    now += 1
    cnt += 1

print(round(money,2))