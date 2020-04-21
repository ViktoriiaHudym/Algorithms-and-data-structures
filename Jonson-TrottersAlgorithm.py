n = int(input("Enter n: "))
sequence=[]

# ініціалузуємо першу перестановку
for i in range(1,n+1):
  sequence.append(i)
print(sequence)

# створюємо допоміжний двовимірний масив, кожен елемент якого має вигляд [-1, n],
# де -1 це напрямок стрілки ліворуч (1 - праворуч)
indices = range(1, n+1)
state = [[-1, idx] for idx in indices]
state = [[-1, n+1]] + state + [[-1, n+1]]

while True:
  # 1.Знаходимо найбільше мобільне число
  mobile = -1
  for idx in indices: #1, 2 ... n
    direction, value = state[idx]
    if value > mobile and value > state[idx+direction][1]:
      # число є мобільним і більшим ніж попереднє мобільне число
      mobile = value
      mobile_index = idx
      mobile_direction = direction
      if mobile == n:
        break
  if mobile == -1:
    # немає мобільних чисел, тобто перестановки завершено
    break

  # 2.Міняємо місцями мобільне число з сусіднім числом, на яке показує стрілка
  sees = mobile_index + mobile_direction
  # оновлюємо допоміжну множину перестановок (двовимірний масив)
  state[mobile_index], state[sees] = state[sees], state[mobile_index]
  # оновлюємо множину перестановок
  sequence[mobile_index-1], sequence[sees-1] = sequence[sees-1], sequence[mobile_index-1]
  print(sequence)

  # 3.Змінюємо напрямок стрілок у всіх чисел більших за мобільне число
  if mobile<n:
    for idx in indices:
      if state[idx][1] > mobile:
        state[idx][0] = -state[idx][0]