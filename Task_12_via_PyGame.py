import pygame
from string import ascii_uppercase as uppercase
from random import choice

WIDTH = 800
HEIGHT = 600
FPS = 30


BLACK = (0, 0, 0)
WHITE = (255, 255, 255)
RED = (255, 0, 0)
GREEN = (0, 255, 0)
BLUE = (0, 0, 255)

AS_IF_BLACK = (50, 50, 50)
DARK_GREY = (80, 80, 80)
GREY = (100, 100, 100)
LIGHT_GREY = (128, 128, 128)
VERY_LIGHT_GREY = (170, 170, 170)
AS_IF_WHITE = (200, 200, 200)

NAVY = (0, 0, 128)
YELLOW = (225, 210, 100)
TEAL = (100, 100, 225)
CYAN = (50, 150, 200)


pygame.font.init()
font_name = pygame.font.match_font('arial')


def draw_text(surf, text, size, colour, coors):
    font = pygame.font.Font(font_name, size)
    text_surface = font.render(text, True, colour)
    ##text_surface.fill((128, 128, 128))
    text_rect = text_surface.get_rect()
    text_rect.center = coors
    surf.blit(text_surface, text_rect)


pygame.init()
screen = pygame.display.set_mode((WIDTH, HEIGHT))
pygame.display.set_caption("Algorithm_realization_on_PyGame")
clock = pygame.time.Clock()

all_sprites = pygame.sprite.Group()
digits_buttons = pygame.sprite.Group()
yes_no_buttons = pygame.sprite.Group()
letters_buttons = pygame.sprite.Group()



for i in range(2, 6):
    cur_button = pygame.sprite.Sprite()
    cur_button.image = pygame.Surface((50, 50))
    cur_button.image.fill(TEAL)

    cur_button.value = i

    cur_button.rect = cur_button.image.get_rect()
    cur_button.rect.topleft = (50 + i * 100, 100)

    draw_text(cur_button.image, str(i), 40, BLACK, (cur_button.rect.w / 2, cur_button.rect.h / 2))

    cur_button.add(all_sprites, digits_buttons)


for v in "YES", "NO":
    cur_button = pygame.sprite.Sprite()
    cur_button.image = pygame.Surface((200, 50))
    cur_button.image.fill(TEAL)

    cur_button.value = v

    cur_button.rect = cur_button.image.get_rect()
    cur_button.rect.topleft = (200 + (v == "NO") * 250, 100)

    draw_text(cur_button.image, str(v), 40, BLACK, (cur_button.rect.w / 2, cur_button.rect.h / 2))

    cur_button.add(all_sprites, yes_no_buttons)


for j, row in enumerate(("QWERTYUIOP", "ASDFGHJKL", "ZXCVBNM")):
    for i, v in enumerate(row):
        cur_button = pygame.sprite.Sprite()
        cur_button.image = pygame.Surface((25, 25))
        cur_button.image.fill(TEAL)

        cur_button.value = v

        cur_button.rect = cur_button.image.get_rect()
        cur_button.rect.topleft = (10 + i * 30, 100 + j * 30)

        draw_text(cur_button.image, str(v), 30, BLACK, (cur_button.rect.w / 2, cur_button.rect.h / 2))

        cur_button.add(all_sprites, letters_buttons)


# Цвета
BLACK = (0, 0, 0)
WHITE = (255, 255, 255)
RED = (255, 0, 0)
GREEN = (0, 255, 0)
BLUE = (0, 0, 255)
TEAL = (100, 100, 225)
CYAN = (50, 150, 200)


def generate_word():
    word = ""
    for i in range(4):
        word += choice(uppercase)
    return word


def vowels_count(word):
    vowels = "AEIOUY"
    count = 0
    for r in word:
        if r in vowels:
            count += 1
    return count


def bubble_sort(arr):
    n = len(arr)
    for k in range(n, 1, -1):
        for i in range(k-1):
            if arr[i] > arr[i+1]:
                arr[i], arr[i+1] = arr[i+1], arr[i]
    return arr

def digit_choosing(click_coors):
    for cur_button in digits_buttons:
        if cur_button.rect.collidepoint(click_coors):
            return cur_button.value
    return None


def the_way_choosing(click_coors):
    for cur_button in yes_no_buttons:
        if cur_button.rect.collidepoint(click_coors):
            return cur_button.value
    return None


def letter_choosing(click_coors):
    for cur_button in letters_buttons:
        if cur_button.rect.collidepoint(click_coors):
            return cur_button.value
    return None


def draw_matrix():
    ...


# выбираем размер матрицы
digit_chosen = False
while not digit_chosen:
    for event in pygame.event.get():
        if event.type == pygame.MOUSEBUTTONDOWN:
            res = digit_choosing(event.pos)
            if res:
                M = res
                digit_chosen = True


    screen.fill(YELLOW)
    draw_text(screen, "Выберите размер вашей матрицы.", 40, BLACK, (WIDTH / 2, 50))
    digits_buttons.draw(screen)

    pygame.display.flip()

    clock.tick(FPS)

matr = [["" for _ in range(M)] for _ in range(M)]

# выбираем, будем ли мы вводить числа самостоятельно
the_way_chosen = False
while not the_way_chosen:
    for event in pygame.event.get():
        if event.type == pygame.MOUSEBUTTONDOWN:
            res = the_way_choosing(event.pos)
            if res:
                the_way = res
                the_way_chosen = True

    screen.fill(YELLOW)
    draw_text(screen, "Вы хотите вводить числа самостоятельно?", 40, BLACK, (WIDTH / 2, 50))
    yes_no_buttons.draw(screen)

    pygame.display.flip()

    clock.tick(FPS)


# выбираем
if the_way == "YES":
    for i in range(M):
        for j in range(M):
            word_got = False
            word = ""
            while not word_got:
                for event in pygame.event.get():
                    if event.type == pygame.MOUSEBUTTONDOWN:
                        res = letter_choosing(event.pos)
                        if res:
                            if len(word) < 4:
                                word += res
                                if len(word) == 4:
                                    matr[i][j] = word
                                    word_got = True

                screen.fill(YELLOW)
                draw_text(screen, "Вводите:", 40, BLACK, (WIDTH / 2, 50))
                pygame.draw.rect(screen, AS_IF_WHITE, [500, 25, 200, 50], 5)
                draw_text(screen, word, 40, BLACK, (600, 50))
                letters_buttons.draw(screen)

                pygame.display.flip()

                clock.tick(FPS)

if the_way == "NO":  # генерируем автоматически

    for i in range(M):
        for j in range(M):
            matr[i][j] = generate_word()

        screen.fill(YELLOW)
        draw_text(screen, "Идёт генерация значений; пожалуйста, подождите...", 30, BLACK, (WIDTH / 2, 50))
        yes_no_buttons.draw(screen)

        pygame.display.flip()

        clock.tick(FPS)


arr = list()
for i in range(M):
    for j in range(M):
        arr.append(vowels_count(matr[i][j]))


arr = bubble_sort(arr)


for row in matr:
    print(*row)

print(arr)

pygame.quit()
