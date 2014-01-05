#!/usr/bin/env ruby

size = 8
is64bit = false

print "typedef BitMatrix bit_matrix;\n"

def at(x, y)
  if (x < 0 || x >= 8 || y < 0 || y >= 8) then
    printf "err %d %d\n", x, y
    exit
  end
    
  return 2 ** (y * 8 + x)
end

def count(bx, by, dx, dy, ex, ey)
  x = bx
  y = by
  m = 0
  while (not(x == ex && y == ey))
    m |= at(x, y)
    x += dx
    y += dy
  end
  return m
end

def print_test(var, x, y)
  if not $is64bit then
    if y >= 4 then
      v =  var + ".upper_"
      oy = y - 4
    else
      v = var + ".lower_"
      oy = y
    end
    printf "if ("+v+" & 0x%0xUL) {\n", (at(x, oy))
  else
    printf "if ("+var+".data_ & 0x%0xULL) {\n", (at(x, y))
  end
end

def f(x, y, dx, dy, count, max, bx, by, flip)
  indent = "  " * (count + 2)
  if max > count then
    printf(indent)
    print_test "op_disc", x, y
    f(x + dx, y + dy, dx, dy, count + 1, max, bx, by, flip)
    printf(indent + "} else ")
    print_test "my_disc", x, y
    if flip
      printf(indent + "  my_disc.data_ |= 0x%0xULL;\n", count(bx, by, dx, dy, x, y))
      printf(indent + "  op_disc.data_ ^= 0x%0xULL;\n", count(bx, by, dx, dy, x, y))
    end
    printf(indent + "  count += %d;\n", count + 1)
    printf(indent + "}\n")
  else
    printf(indent)
    print_test "my_disc", x, y
    if flip
      printf(indent + "  my_disc.data_ |= 0x%0xULL;\n", count(bx, by, dx, dy, x, y))
      printf(indent + "  op_disc.data_ ^= 0x%0xULL;\n", count(bx, by, dx, dy, x, y))
    end
    printf(indent + "  count += %d;\n", count + 1)
    printf(indent + "}\n")
  end
end

def print_flip(x, y, dx, dy, max, flip)
  if max >= 0 then
    printf("  ")
    print_test "op_disc", x + dx, y + dy
    f(x + dx*2, y + dy*2, dx, dy, 0, max, x + dx, y + dy, flip)
    printf "  }\n"
  end
end

def min(x, y)
  if x < y then
    return x
  else
    return y
  end
end

size.times { |py|
  size.times { |px|
    printf "static int f_%d%d(bit_matrix& my_disc, bit_matrix& op_disc) {\n", py, px
    printf "  int count = 0;\n"

    # left
    print_flip(px, py, 1, 0, size - px - 3, true)
    print_flip(px, py, -1, 0, px - 2, true)
    print_flip(px, py, 0, 1, size - py - 3, true)
    print_flip(px, py, 0, -1, py - 2, true)

    print_flip(px, py, 1, 1, min(size - px - 3, size - py - 3), true)
    print_flip(px, py, 1, -1, min(size - px - 3, py - 2), true)
    print_flip(px, py, -1, 1, min(px - 2, size - py - 3), true)
    print_flip(px, py, -1, -1, min(px - 2, py - 2), true)

    printf "  return count;\n"
    printf "}\n\n"
  }
}

size.times { |py|
  size.times { |px|
    printf "static int g_%d%d(const bit_matrix& my_disc, const bit_matrix& op_disc) {\n", py, px
    printf "  int count = 0;\n"

    # left
    print_flip(px, py, 1, 0, size - px - 3, false)
    print_flip(px, py, -1, 0, px - 2, false)
    print_flip(px, py, 0, 1, size - py - 3, false)
    print_flip(px, py, 0, -1, py - 2, false)

    print_flip(px, py, 1, 1, min(size - px - 3, size - py - 3), false)
    print_flip(px, py, 1, -1, min(size - px - 3, py - 2), false)
    print_flip(px, py, -1, 1, min(px - 2, size - py - 3), false)
    print_flip(px, py, -1, -1, min(px - 2, py - 2), false)

    printf "  return count;\n"
    printf "}\n\n"
  }
}

print "int (*flip_f[])(bit_matrix&, bit_matrix&) = {\n"
size.times { |y|
  size.times { |x|
    printf "f_%d%d, ", y, x
  }
  printf "\n"
}
print "};\n"

print "int (*count_f[])(const bit_matrix&, const bit_matrix&) = {\n"
size.times { |y|
  size.times { |x|
    printf "g_%d%d, ", y, x
  }
  printf "\n"
}
print "};\n"
