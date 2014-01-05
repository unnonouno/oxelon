typedef BitMatrix bit_matrix;
static int f_00(bit_matrix& my_disc, bit_matrix& op_disc) {
  int count = 0;
  if (op_disc.lower_ & 0x2UL) {
    if (op_disc.lower_ & 0x4UL) {
      if (op_disc.lower_ & 0x8UL) {
        if (op_disc.lower_ & 0x10UL) {
          if (op_disc.lower_ & 0x20UL) {
            if (op_disc.lower_ & 0x40UL) {
              if (my_disc.lower_ & 0x80UL) {
                my_disc.data_ |= 0x7eULL;
                op_disc.data_ ^= 0x7eULL;
                count += 6;
              }
            } else if (my_disc.lower_ & 0x40UL) {
              my_disc.data_ |= 0x3eULL;
              op_disc.data_ ^= 0x3eULL;
              count += 5;
            }
          } else if (my_disc.lower_ & 0x20UL) {
            my_disc.data_ |= 0x1eULL;
            op_disc.data_ ^= 0x1eULL;
            count += 4;
          }
        } else if (my_disc.lower_ & 0x10UL) {
          my_disc.data_ |= 0xeULL;
          op_disc.data_ ^= 0xeULL;
          count += 3;
        }
      } else if (my_disc.lower_ & 0x8UL) {
        my_disc.data_ |= 0x6ULL;
        op_disc.data_ ^= 0x6ULL;
        count += 2;
      }
    } else if (my_disc.lower_ & 0x4UL) {
      my_disc.data_ |= 0x2ULL;
      op_disc.data_ ^= 0x2ULL;
      count += 1;
    }
  }
  if (op_disc.lower_ & 0x100UL) {
    if (op_disc.lower_ & 0x10000UL) {
      if (op_disc.lower_ & 0x1000000UL) {
        if (op_disc.upper_ & 0x1UL) {
          if (op_disc.upper_ & 0x100UL) {
            if (op_disc.upper_ & 0x10000UL) {
              if (my_disc.upper_ & 0x1000000UL) {
                my_disc.data_ |= 0x1010101010100ULL;
                op_disc.data_ ^= 0x1010101010100ULL;
                count += 6;
              }
            } else if (my_disc.upper_ & 0x10000UL) {
              my_disc.data_ |= 0x10101010100ULL;
              op_disc.data_ ^= 0x10101010100ULL;
              count += 5;
            }
          } else if (my_disc.upper_ & 0x100UL) {
            my_disc.data_ |= 0x101010100ULL;
            op_disc.data_ ^= 0x101010100ULL;
            count += 4;
          }
        } else if (my_disc.upper_ & 0x1UL) {
          my_disc.data_ |= 0x1010100ULL;
          op_disc.data_ ^= 0x1010100ULL;
          count += 3;
        }
      } else if (my_disc.lower_ & 0x1000000UL) {
        my_disc.data_ |= 0x10100ULL;
        op_disc.data_ ^= 0x10100ULL;
        count += 2;
      }
    } else if (my_disc.lower_ & 0x10000UL) {
      my_disc.data_ |= 0x100ULL;
      op_disc.data_ ^= 0x100ULL;
      count += 1;
    }
  }
  if (op_disc.lower_ & 0x200UL) {
    if (op_disc.lower_ & 0x40000UL) {
      if (op_disc.lower_ & 0x8000000UL) {
        if (op_disc.upper_ & 0x10UL) {
          if (op_disc.upper_ & 0x2000UL) {
            if (op_disc.upper_ & 0x400000UL) {
              if (my_disc.upper_ & 0x80000000UL) {
                my_disc.data_ |= 0x40201008040200ULL;
                op_disc.data_ ^= 0x40201008040200ULL;
                count += 6;
              }
            } else if (my_disc.upper_ & 0x400000UL) {
              my_disc.data_ |= 0x201008040200ULL;
              op_disc.data_ ^= 0x201008040200ULL;
              count += 5;
            }
          } else if (my_disc.upper_ & 0x2000UL) {
            my_disc.data_ |= 0x1008040200ULL;
            op_disc.data_ ^= 0x1008040200ULL;
            count += 4;
          }
        } else if (my_disc.upper_ & 0x10UL) {
          my_disc.data_ |= 0x8040200ULL;
          op_disc.data_ ^= 0x8040200ULL;
          count += 3;
        }
      } else if (my_disc.lower_ & 0x8000000UL) {
        my_disc.data_ |= 0x40200ULL;
        op_disc.data_ ^= 0x40200ULL;
        count += 2;
      }
    } else if (my_disc.lower_ & 0x40000UL) {
      my_disc.data_ |= 0x200ULL;
      op_disc.data_ ^= 0x200ULL;
      count += 1;
    }
  }
  return count;
}

static int f_01(bit_matrix& my_disc, bit_matrix& op_disc) {
  int count = 0;
  if (op_disc.lower_ & 0x4UL) {
    if (op_disc.lower_ & 0x8UL) {
      if (op_disc.lower_ & 0x10UL) {
        if (op_disc.lower_ & 0x20UL) {
          if (op_disc.lower_ & 0x40UL) {
            if (my_disc.lower_ & 0x80UL) {
              my_disc.data_ |= 0x7cULL;
              op_disc.data_ ^= 0x7cULL;
              count += 5;
            }
          } else if (my_disc.lower_ & 0x40UL) {
            my_disc.data_ |= 0x3cULL;
            op_disc.data_ ^= 0x3cULL;
            count += 4;
          }
        } else if (my_disc.lower_ & 0x20UL) {
          my_disc.data_ |= 0x1cULL;
          op_disc.data_ ^= 0x1cULL;
          count += 3;
        }
      } else if (my_disc.lower_ & 0x10UL) {
        my_disc.data_ |= 0xcULL;
        op_disc.data_ ^= 0xcULL;
        count += 2;
      }
    } else if (my_disc.lower_ & 0x8UL) {
      my_disc.data_ |= 0x4ULL;
      op_disc.data_ ^= 0x4ULL;
      count += 1;
    }
  }
  if (op_disc.lower_ & 0x200UL) {
    if (op_disc.lower_ & 0x20000UL) {
      if (op_disc.lower_ & 0x2000000UL) {
        if (op_disc.upper_ & 0x2UL) {
          if (op_disc.upper_ & 0x200UL) {
            if (op_disc.upper_ & 0x20000UL) {
              if (my_disc.upper_ & 0x2000000UL) {
                my_disc.data_ |= 0x2020202020200ULL;
                op_disc.data_ ^= 0x2020202020200ULL;
                count += 6;
              }
            } else if (my_disc.upper_ & 0x20000UL) {
              my_disc.data_ |= 0x20202020200ULL;
              op_disc.data_ ^= 0x20202020200ULL;
              count += 5;
            }
          } else if (my_disc.upper_ & 0x200UL) {
            my_disc.data_ |= 0x202020200ULL;
            op_disc.data_ ^= 0x202020200ULL;
            count += 4;
          }
        } else if (my_disc.upper_ & 0x2UL) {
          my_disc.data_ |= 0x2020200ULL;
          op_disc.data_ ^= 0x2020200ULL;
          count += 3;
        }
      } else if (my_disc.lower_ & 0x2000000UL) {
        my_disc.data_ |= 0x20200ULL;
        op_disc.data_ ^= 0x20200ULL;
        count += 2;
      }
    } else if (my_disc.lower_ & 0x20000UL) {
      my_disc.data_ |= 0x200ULL;
      op_disc.data_ ^= 0x200ULL;
      count += 1;
    }
  }
  if (op_disc.lower_ & 0x400UL) {
    if (op_disc.lower_ & 0x80000UL) {
      if (op_disc.lower_ & 0x10000000UL) {
        if (op_disc.upper_ & 0x20UL) {
          if (op_disc.upper_ & 0x4000UL) {
            if (my_disc.upper_ & 0x800000UL) {
              my_disc.data_ |= 0x402010080400ULL;
              op_disc.data_ ^= 0x402010080400ULL;
              count += 5;
            }
          } else if (my_disc.upper_ & 0x4000UL) {
            my_disc.data_ |= 0x2010080400ULL;
            op_disc.data_ ^= 0x2010080400ULL;
            count += 4;
          }
        } else if (my_disc.upper_ & 0x20UL) {
          my_disc.data_ |= 0x10080400ULL;
          op_disc.data_ ^= 0x10080400ULL;
          count += 3;
        }
      } else if (my_disc.lower_ & 0x10000000UL) {
        my_disc.data_ |= 0x80400ULL;
        op_disc.data_ ^= 0x80400ULL;
        count += 2;
      }
    } else if (my_disc.lower_ & 0x80000UL) {
      my_disc.data_ |= 0x400ULL;
      op_disc.data_ ^= 0x400ULL;
      count += 1;
    }
  }
  return count;
}

static int f_02(bit_matrix& my_disc, bit_matrix& op_disc) {
  int count = 0;
  if (op_disc.lower_ & 0x8UL) {
    if (op_disc.lower_ & 0x10UL) {
      if (op_disc.lower_ & 0x20UL) {
        if (op_disc.lower_ & 0x40UL) {
          if (my_disc.lower_ & 0x80UL) {
            my_disc.data_ |= 0x78ULL;
            op_disc.data_ ^= 0x78ULL;
            count += 4;
          }
        } else if (my_disc.lower_ & 0x40UL) {
          my_disc.data_ |= 0x38ULL;
          op_disc.data_ ^= 0x38ULL;
          count += 3;
        }
      } else if (my_disc.lower_ & 0x20UL) {
        my_disc.data_ |= 0x18ULL;
        op_disc.data_ ^= 0x18ULL;
        count += 2;
      }
    } else if (my_disc.lower_ & 0x10UL) {
      my_disc.data_ |= 0x8ULL;
      op_disc.data_ ^= 0x8ULL;
      count += 1;
    }
  }
  if (op_disc.lower_ & 0x2UL) {
    if (my_disc.lower_ & 0x1UL) {
      my_disc.data_ |= 0x2ULL;
      op_disc.data_ ^= 0x2ULL;
      count += 1;
    }
  }
  if (op_disc.lower_ & 0x400UL) {
    if (op_disc.lower_ & 0x40000UL) {
      if (op_disc.lower_ & 0x4000000UL) {
        if (op_disc.upper_ & 0x4UL) {
          if (op_disc.upper_ & 0x400UL) {
            if (op_disc.upper_ & 0x40000UL) {
              if (my_disc.upper_ & 0x4000000UL) {
                my_disc.data_ |= 0x4040404040400ULL;
                op_disc.data_ ^= 0x4040404040400ULL;
                count += 6;
              }
            } else if (my_disc.upper_ & 0x40000UL) {
              my_disc.data_ |= 0x40404040400ULL;
              op_disc.data_ ^= 0x40404040400ULL;
              count += 5;
            }
          } else if (my_disc.upper_ & 0x400UL) {
            my_disc.data_ |= 0x404040400ULL;
            op_disc.data_ ^= 0x404040400ULL;
            count += 4;
          }
        } else if (my_disc.upper_ & 0x4UL) {
          my_disc.data_ |= 0x4040400ULL;
          op_disc.data_ ^= 0x4040400ULL;
          count += 3;
        }
      } else if (my_disc.lower_ & 0x4000000UL) {
        my_disc.data_ |= 0x40400ULL;
        op_disc.data_ ^= 0x40400ULL;
        count += 2;
      }
    } else if (my_disc.lower_ & 0x40000UL) {
      my_disc.data_ |= 0x400ULL;
      op_disc.data_ ^= 0x400ULL;
      count += 1;
    }
  }
  if (op_disc.lower_ & 0x800UL) {
    if (op_disc.lower_ & 0x100000UL) {
      if (op_disc.lower_ & 0x20000000UL) {
        if (op_disc.upper_ & 0x40UL) {
          if (my_disc.upper_ & 0x8000UL) {
            my_disc.data_ |= 0x4020100800ULL;
            op_disc.data_ ^= 0x4020100800ULL;
            count += 4;
          }
        } else if (my_disc.upper_ & 0x40UL) {
          my_disc.data_ |= 0x20100800ULL;
          op_disc.data_ ^= 0x20100800ULL;
          count += 3;
        }
      } else if (my_disc.lower_ & 0x20000000UL) {
        my_disc.data_ |= 0x100800ULL;
        op_disc.data_ ^= 0x100800ULL;
        count += 2;
      }
    } else if (my_disc.lower_ & 0x100000UL) {
      my_disc.data_ |= 0x800ULL;
      op_disc.data_ ^= 0x800ULL;
      count += 1;
    }
  }
  if (op_disc.lower_ & 0x200UL) {
    if (my_disc.lower_ & 0x10000UL) {
      my_disc.data_ |= 0x200ULL;
      op_disc.data_ ^= 0x200ULL;
      count += 1;
    }
  }
  return count;
}

static int f_03(bit_matrix& my_disc, bit_matrix& op_disc) {
  int count = 0;
  if (op_disc.lower_ & 0x10UL) {
    if (op_disc.lower_ & 0x20UL) {
      if (op_disc.lower_ & 0x40UL) {
        if (my_disc.lower_ & 0x80UL) {
          my_disc.data_ |= 0x70ULL;
          op_disc.data_ ^= 0x70ULL;
          count += 3;
        }
      } else if (my_disc.lower_ & 0x40UL) {
        my_disc.data_ |= 0x30ULL;
        op_disc.data_ ^= 0x30ULL;
        count += 2;
      }
    } else if (my_disc.lower_ & 0x20UL) {
      my_disc.data_ |= 0x10ULL;
      op_disc.data_ ^= 0x10ULL;
      count += 1;
    }
  }
  if (op_disc.lower_ & 0x4UL) {
    if (op_disc.lower_ & 0x2UL) {
      if (my_disc.lower_ & 0x1UL) {
        my_disc.data_ |= 0x6ULL;
        op_disc.data_ ^= 0x6ULL;
        count += 2;
      }
    } else if (my_disc.lower_ & 0x2UL) {
      my_disc.data_ |= 0x4ULL;
      op_disc.data_ ^= 0x4ULL;
      count += 1;
    }
  }
  if (op_disc.lower_ & 0x800UL) {
    if (op_disc.lower_ & 0x80000UL) {
      if (op_disc.lower_ & 0x8000000UL) {
        if (op_disc.upper_ & 0x8UL) {
          if (op_disc.upper_ & 0x800UL) {
            if (op_disc.upper_ & 0x80000UL) {
              if (my_disc.upper_ & 0x8000000UL) {
                my_disc.data_ |= 0x8080808080800ULL;
                op_disc.data_ ^= 0x8080808080800ULL;
                count += 6;
              }
            } else if (my_disc.upper_ & 0x80000UL) {
              my_disc.data_ |= 0x80808080800ULL;
              op_disc.data_ ^= 0x80808080800ULL;
              count += 5;
            }
          } else if (my_disc.upper_ & 0x800UL) {
            my_disc.data_ |= 0x808080800ULL;
            op_disc.data_ ^= 0x808080800ULL;
            count += 4;
          }
        } else if (my_disc.upper_ & 0x8UL) {
          my_disc.data_ |= 0x8080800ULL;
          op_disc.data_ ^= 0x8080800ULL;
          count += 3;
        }
      } else if (my_disc.lower_ & 0x8000000UL) {
        my_disc.data_ |= 0x80800ULL;
        op_disc.data_ ^= 0x80800ULL;
        count += 2;
      }
    } else if (my_disc.lower_ & 0x80000UL) {
      my_disc.data_ |= 0x800ULL;
      op_disc.data_ ^= 0x800ULL;
      count += 1;
    }
  }
  if (op_disc.lower_ & 0x1000UL) {
    if (op_disc.lower_ & 0x200000UL) {
      if (op_disc.lower_ & 0x40000000UL) {
        if (my_disc.upper_ & 0x80UL) {
          my_disc.data_ |= 0x40201000ULL;
          op_disc.data_ ^= 0x40201000ULL;
          count += 3;
        }
      } else if (my_disc.lower_ & 0x40000000UL) {
        my_disc.data_ |= 0x201000ULL;
        op_disc.data_ ^= 0x201000ULL;
        count += 2;
      }
    } else if (my_disc.lower_ & 0x200000UL) {
      my_disc.data_ |= 0x1000ULL;
      op_disc.data_ ^= 0x1000ULL;
      count += 1;
    }
  }
  if (op_disc.lower_ & 0x400UL) {
    if (op_disc.lower_ & 0x20000UL) {
      if (my_disc.lower_ & 0x1000000UL) {
        my_disc.data_ |= 0x20400ULL;
        op_disc.data_ ^= 0x20400ULL;
        count += 2;
      }
    } else if (my_disc.lower_ & 0x20000UL) {
      my_disc.data_ |= 0x400ULL;
      op_disc.data_ ^= 0x400ULL;
      count += 1;
    }
  }
  return count;
}

static int f_04(bit_matrix& my_disc, bit_matrix& op_disc) {
  int count = 0;
  if (op_disc.lower_ & 0x20UL) {
    if (op_disc.lower_ & 0x40UL) {
      if (my_disc.lower_ & 0x80UL) {
        my_disc.data_ |= 0x60ULL;
        op_disc.data_ ^= 0x60ULL;
        count += 2;
      }
    } else if (my_disc.lower_ & 0x40UL) {
      my_disc.data_ |= 0x20ULL;
      op_disc.data_ ^= 0x20ULL;
      count += 1;
    }
  }
  if (op_disc.lower_ & 0x8UL) {
    if (op_disc.lower_ & 0x4UL) {
      if (op_disc.lower_ & 0x2UL) {
        if (my_disc.lower_ & 0x1UL) {
          my_disc.data_ |= 0xeULL;
          op_disc.data_ ^= 0xeULL;
          count += 3;
        }
      } else if (my_disc.lower_ & 0x2UL) {
        my_disc.data_ |= 0xcULL;
        op_disc.data_ ^= 0xcULL;
        count += 2;
      }
    } else if (my_disc.lower_ & 0x4UL) {
      my_disc.data_ |= 0x8ULL;
      op_disc.data_ ^= 0x8ULL;
      count += 1;
    }
  }
  if (op_disc.lower_ & 0x1000UL) {
    if (op_disc.lower_ & 0x100000UL) {
      if (op_disc.lower_ & 0x10000000UL) {
        if (op_disc.upper_ & 0x10UL) {
          if (op_disc.upper_ & 0x1000UL) {
            if (op_disc.upper_ & 0x100000UL) {
              if (my_disc.upper_ & 0x10000000UL) {
                my_disc.data_ |= 0x10101010101000ULL;
                op_disc.data_ ^= 0x10101010101000ULL;
                count += 6;
              }
            } else if (my_disc.upper_ & 0x100000UL) {
              my_disc.data_ |= 0x101010101000ULL;
              op_disc.data_ ^= 0x101010101000ULL;
              count += 5;
            }
          } else if (my_disc.upper_ & 0x1000UL) {
            my_disc.data_ |= 0x1010101000ULL;
            op_disc.data_ ^= 0x1010101000ULL;
            count += 4;
          }
        } else if (my_disc.upper_ & 0x10UL) {
          my_disc.data_ |= 0x10101000ULL;
          op_disc.data_ ^= 0x10101000ULL;
          count += 3;
        }
      } else if (my_disc.lower_ & 0x10000000UL) {
        my_disc.data_ |= 0x101000ULL;
        op_disc.data_ ^= 0x101000ULL;
        count += 2;
      }
    } else if (my_disc.lower_ & 0x100000UL) {
      my_disc.data_ |= 0x1000ULL;
      op_disc.data_ ^= 0x1000ULL;
      count += 1;
    }
  }
  if (op_disc.lower_ & 0x2000UL) {
    if (op_disc.lower_ & 0x400000UL) {
      if (my_disc.lower_ & 0x80000000UL) {
        my_disc.data_ |= 0x402000ULL;
        op_disc.data_ ^= 0x402000ULL;
        count += 2;
      }
    } else if (my_disc.lower_ & 0x400000UL) {
      my_disc.data_ |= 0x2000ULL;
      op_disc.data_ ^= 0x2000ULL;
      count += 1;
    }
  }
  if (op_disc.lower_ & 0x800UL) {
    if (op_disc.lower_ & 0x40000UL) {
      if (op_disc.lower_ & 0x2000000UL) {
        if (my_disc.upper_ & 0x1UL) {
          my_disc.data_ |= 0x2040800ULL;
          op_disc.data_ ^= 0x2040800ULL;
          count += 3;
        }
      } else if (my_disc.lower_ & 0x2000000UL) {
        my_disc.data_ |= 0x40800ULL;
        op_disc.data_ ^= 0x40800ULL;
        count += 2;
      }
    } else if (my_disc.lower_ & 0x40000UL) {
      my_disc.data_ |= 0x800ULL;
      op_disc.data_ ^= 0x800ULL;
      count += 1;
    }
  }
  return count;
}

static int f_05(bit_matrix& my_disc, bit_matrix& op_disc) {
  int count = 0;
  if (op_disc.lower_ & 0x40UL) {
    if (my_disc.lower_ & 0x80UL) {
      my_disc.data_ |= 0x40ULL;
      op_disc.data_ ^= 0x40ULL;
      count += 1;
    }
  }
  if (op_disc.lower_ & 0x10UL) {
    if (op_disc.lower_ & 0x8UL) {
      if (op_disc.lower_ & 0x4UL) {
        if (op_disc.lower_ & 0x2UL) {
          if (my_disc.lower_ & 0x1UL) {
            my_disc.data_ |= 0x1eULL;
            op_disc.data_ ^= 0x1eULL;
            count += 4;
          }
        } else if (my_disc.lower_ & 0x2UL) {
          my_disc.data_ |= 0x1cULL;
          op_disc.data_ ^= 0x1cULL;
          count += 3;
        }
      } else if (my_disc.lower_ & 0x4UL) {
        my_disc.data_ |= 0x18ULL;
        op_disc.data_ ^= 0x18ULL;
        count += 2;
      }
    } else if (my_disc.lower_ & 0x8UL) {
      my_disc.data_ |= 0x10ULL;
      op_disc.data_ ^= 0x10ULL;
      count += 1;
    }
  }
  if (op_disc.lower_ & 0x2000UL) {
    if (op_disc.lower_ & 0x200000UL) {
      if (op_disc.lower_ & 0x20000000UL) {
        if (op_disc.upper_ & 0x20UL) {
          if (op_disc.upper_ & 0x2000UL) {
            if (op_disc.upper_ & 0x200000UL) {
              if (my_disc.upper_ & 0x20000000UL) {
                my_disc.data_ |= 0x20202020202000ULL;
                op_disc.data_ ^= 0x20202020202000ULL;
                count += 6;
              }
            } else if (my_disc.upper_ & 0x200000UL) {
              my_disc.data_ |= 0x202020202000ULL;
              op_disc.data_ ^= 0x202020202000ULL;
              count += 5;
            }
          } else if (my_disc.upper_ & 0x2000UL) {
            my_disc.data_ |= 0x2020202000ULL;
            op_disc.data_ ^= 0x2020202000ULL;
            count += 4;
          }
        } else if (my_disc.upper_ & 0x20UL) {
          my_disc.data_ |= 0x20202000ULL;
          op_disc.data_ ^= 0x20202000ULL;
          count += 3;
        }
      } else if (my_disc.lower_ & 0x20000000UL) {
        my_disc.data_ |= 0x202000ULL;
        op_disc.data_ ^= 0x202000ULL;
        count += 2;
      }
    } else if (my_disc.lower_ & 0x200000UL) {
      my_disc.data_ |= 0x2000ULL;
      op_disc.data_ ^= 0x2000ULL;
      count += 1;
    }
  }
  if (op_disc.lower_ & 0x4000UL) {
    if (my_disc.lower_ & 0x800000UL) {
      my_disc.data_ |= 0x4000ULL;
      op_disc.data_ ^= 0x4000ULL;
      count += 1;
    }
  }
  if (op_disc.lower_ & 0x1000UL) {
    if (op_disc.lower_ & 0x80000UL) {
      if (op_disc.lower_ & 0x4000000UL) {
        if (op_disc.upper_ & 0x2UL) {
          if (my_disc.upper_ & 0x100UL) {
            my_disc.data_ |= 0x204081000ULL;
            op_disc.data_ ^= 0x204081000ULL;
            count += 4;
          }
        } else if (my_disc.upper_ & 0x2UL) {
          my_disc.data_ |= 0x4081000ULL;
          op_disc.data_ ^= 0x4081000ULL;
          count += 3;
        }
      } else if (my_disc.lower_ & 0x4000000UL) {
        my_disc.data_ |= 0x81000ULL;
        op_disc.data_ ^= 0x81000ULL;
        count += 2;
      }
    } else if (my_disc.lower_ & 0x80000UL) {
      my_disc.data_ |= 0x1000ULL;
      op_disc.data_ ^= 0x1000ULL;
      count += 1;
    }
  }
  return count;
}

static int f_06(bit_matrix& my_disc, bit_matrix& op_disc) {
  int count = 0;
  if (op_disc.lower_ & 0x20UL) {
    if (op_disc.lower_ & 0x10UL) {
      if (op_disc.lower_ & 0x8UL) {
        if (op_disc.lower_ & 0x4UL) {
          if (op_disc.lower_ & 0x2UL) {
            if (my_disc.lower_ & 0x1UL) {
              my_disc.data_ |= 0x3eULL;
              op_disc.data_ ^= 0x3eULL;
              count += 5;
            }
          } else if (my_disc.lower_ & 0x2UL) {
            my_disc.data_ |= 0x3cULL;
            op_disc.data_ ^= 0x3cULL;
            count += 4;
          }
        } else if (my_disc.lower_ & 0x4UL) {
          my_disc.data_ |= 0x38ULL;
          op_disc.data_ ^= 0x38ULL;
          count += 3;
        }
      } else if (my_disc.lower_ & 0x8UL) {
        my_disc.data_ |= 0x30ULL;
        op_disc.data_ ^= 0x30ULL;
        count += 2;
      }
    } else if (my_disc.lower_ & 0x10UL) {
      my_disc.data_ |= 0x20ULL;
      op_disc.data_ ^= 0x20ULL;
      count += 1;
    }
  }
  if (op_disc.lower_ & 0x4000UL) {
    if (op_disc.lower_ & 0x400000UL) {
      if (op_disc.lower_ & 0x40000000UL) {
        if (op_disc.upper_ & 0x40UL) {
          if (op_disc.upper_ & 0x4000UL) {
            if (op_disc.upper_ & 0x400000UL) {
              if (my_disc.upper_ & 0x40000000UL) {
                my_disc.data_ |= 0x40404040404000ULL;
                op_disc.data_ ^= 0x40404040404000ULL;
                count += 6;
              }
            } else if (my_disc.upper_ & 0x400000UL) {
              my_disc.data_ |= 0x404040404000ULL;
              op_disc.data_ ^= 0x404040404000ULL;
              count += 5;
            }
          } else if (my_disc.upper_ & 0x4000UL) {
            my_disc.data_ |= 0x4040404000ULL;
            op_disc.data_ ^= 0x4040404000ULL;
            count += 4;
          }
        } else if (my_disc.upper_ & 0x40UL) {
          my_disc.data_ |= 0x40404000ULL;
          op_disc.data_ ^= 0x40404000ULL;
          count += 3;
        }
      } else if (my_disc.lower_ & 0x40000000UL) {
        my_disc.data_ |= 0x404000ULL;
        op_disc.data_ ^= 0x404000ULL;
        count += 2;
      }
    } else if (my_disc.lower_ & 0x400000UL) {
      my_disc.data_ |= 0x4000ULL;
      op_disc.data_ ^= 0x4000ULL;
      count += 1;
    }
  }
  if (op_disc.lower_ & 0x2000UL) {
    if (op_disc.lower_ & 0x100000UL) {
      if (op_disc.lower_ & 0x8000000UL) {
        if (op_disc.upper_ & 0x4UL) {
          if (op_disc.upper_ & 0x200UL) {
            if (my_disc.upper_ & 0x10000UL) {
              my_disc.data_ |= 0x20408102000ULL;
              op_disc.data_ ^= 0x20408102000ULL;
              count += 5;
            }
          } else if (my_disc.upper_ & 0x200UL) {
            my_disc.data_ |= 0x408102000ULL;
            op_disc.data_ ^= 0x408102000ULL;
            count += 4;
          }
        } else if (my_disc.upper_ & 0x4UL) {
          my_disc.data_ |= 0x8102000ULL;
          op_disc.data_ ^= 0x8102000ULL;
          count += 3;
        }
      } else if (my_disc.lower_ & 0x8000000UL) {
        my_disc.data_ |= 0x102000ULL;
        op_disc.data_ ^= 0x102000ULL;
        count += 2;
      }
    } else if (my_disc.lower_ & 0x100000UL) {
      my_disc.data_ |= 0x2000ULL;
      op_disc.data_ ^= 0x2000ULL;
      count += 1;
    }
  }
  return count;
}

static int f_07(bit_matrix& my_disc, bit_matrix& op_disc) {
  int count = 0;
  if (op_disc.lower_ & 0x40UL) {
    if (op_disc.lower_ & 0x20UL) {
      if (op_disc.lower_ & 0x10UL) {
        if (op_disc.lower_ & 0x8UL) {
          if (op_disc.lower_ & 0x4UL) {
            if (op_disc.lower_ & 0x2UL) {
              if (my_disc.lower_ & 0x1UL) {
                my_disc.data_ |= 0x7eULL;
                op_disc.data_ ^= 0x7eULL;
                count += 6;
              }
            } else if (my_disc.lower_ & 0x2UL) {
              my_disc.data_ |= 0x7cULL;
              op_disc.data_ ^= 0x7cULL;
              count += 5;
            }
          } else if (my_disc.lower_ & 0x4UL) {
            my_disc.data_ |= 0x78ULL;
            op_disc.data_ ^= 0x78ULL;
            count += 4;
          }
        } else if (my_disc.lower_ & 0x8UL) {
          my_disc.data_ |= 0x70ULL;
          op_disc.data_ ^= 0x70ULL;
          count += 3;
        }
      } else if (my_disc.lower_ & 0x10UL) {
        my_disc.data_ |= 0x60ULL;
        op_disc.data_ ^= 0x60ULL;
        count += 2;
      }
    } else if (my_disc.lower_ & 0x20UL) {
      my_disc.data_ |= 0x40ULL;
      op_disc.data_ ^= 0x40ULL;
      count += 1;
    }
  }
  if (op_disc.lower_ & 0x8000UL) {
    if (op_disc.lower_ & 0x800000UL) {
      if (op_disc.lower_ & 0x80000000UL) {
        if (op_disc.upper_ & 0x80UL) {
          if (op_disc.upper_ & 0x8000UL) {
            if (op_disc.upper_ & 0x800000UL) {
              if (my_disc.upper_ & 0x80000000UL) {
                my_disc.data_ |= 0x80808080808000ULL;
                op_disc.data_ ^= 0x80808080808000ULL;
                count += 6;
              }
            } else if (my_disc.upper_ & 0x800000UL) {
              my_disc.data_ |= 0x808080808000ULL;
              op_disc.data_ ^= 0x808080808000ULL;
              count += 5;
            }
          } else if (my_disc.upper_ & 0x8000UL) {
            my_disc.data_ |= 0x8080808000ULL;
            op_disc.data_ ^= 0x8080808000ULL;
            count += 4;
          }
        } else if (my_disc.upper_ & 0x80UL) {
          my_disc.data_ |= 0x80808000ULL;
          op_disc.data_ ^= 0x80808000ULL;
          count += 3;
        }
      } else if (my_disc.lower_ & 0x80000000UL) {
        my_disc.data_ |= 0x808000ULL;
        op_disc.data_ ^= 0x808000ULL;
        count += 2;
      }
    } else if (my_disc.lower_ & 0x800000UL) {
      my_disc.data_ |= 0x8000ULL;
      op_disc.data_ ^= 0x8000ULL;
      count += 1;
    }
  }
  if (op_disc.lower_ & 0x4000UL) {
    if (op_disc.lower_ & 0x200000UL) {
      if (op_disc.lower_ & 0x10000000UL) {
        if (op_disc.upper_ & 0x8UL) {
          if (op_disc.upper_ & 0x400UL) {
            if (op_disc.upper_ & 0x20000UL) {
              if (my_disc.upper_ & 0x1000000UL) {
                my_disc.data_ |= 0x2040810204000ULL;
                op_disc.data_ ^= 0x2040810204000ULL;
                count += 6;
              }
            } else if (my_disc.upper_ & 0x20000UL) {
              my_disc.data_ |= 0x40810204000ULL;
              op_disc.data_ ^= 0x40810204000ULL;
              count += 5;
            }
          } else if (my_disc.upper_ & 0x400UL) {
            my_disc.data_ |= 0x810204000ULL;
            op_disc.data_ ^= 0x810204000ULL;
            count += 4;
          }
        } else if (my_disc.upper_ & 0x8UL) {
          my_disc.data_ |= 0x10204000ULL;
          op_disc.data_ ^= 0x10204000ULL;
          count += 3;
        }
      } else if (my_disc.lower_ & 0x10000000UL) {
        my_disc.data_ |= 0x204000ULL;
        op_disc.data_ ^= 0x204000ULL;
        count += 2;
      }
    } else if (my_disc.lower_ & 0x200000UL) {
      my_disc.data_ |= 0x4000ULL;
      op_disc.data_ ^= 0x4000ULL;
      count += 1;
    }
  }
  return count;
}

static int f_10(bit_matrix& my_disc, bit_matrix& op_disc) {
  int count = 0;
  if (op_disc.lower_ & 0x200UL) {
    if (op_disc.lower_ & 0x400UL) {
      if (op_disc.lower_ & 0x800UL) {
        if (op_disc.lower_ & 0x1000UL) {
          if (op_disc.lower_ & 0x2000UL) {
            if (op_disc.lower_ & 0x4000UL) {
              if (my_disc.lower_ & 0x8000UL) {
                my_disc.data_ |= 0x7e00ULL;
                op_disc.data_ ^= 0x7e00ULL;
                count += 6;
              }
            } else if (my_disc.lower_ & 0x4000UL) {
              my_disc.data_ |= 0x3e00ULL;
              op_disc.data_ ^= 0x3e00ULL;
              count += 5;
            }
          } else if (my_disc.lower_ & 0x2000UL) {
            my_disc.data_ |= 0x1e00ULL;
            op_disc.data_ ^= 0x1e00ULL;
            count += 4;
          }
        } else if (my_disc.lower_ & 0x1000UL) {
          my_disc.data_ |= 0xe00ULL;
          op_disc.data_ ^= 0xe00ULL;
          count += 3;
        }
      } else if (my_disc.lower_ & 0x800UL) {
        my_disc.data_ |= 0x600ULL;
        op_disc.data_ ^= 0x600ULL;
        count += 2;
      }
    } else if (my_disc.lower_ & 0x400UL) {
      my_disc.data_ |= 0x200ULL;
      op_disc.data_ ^= 0x200ULL;
      count += 1;
    }
  }
  if (op_disc.lower_ & 0x10000UL) {
    if (op_disc.lower_ & 0x1000000UL) {
      if (op_disc.upper_ & 0x1UL) {
        if (op_disc.upper_ & 0x100UL) {
          if (op_disc.upper_ & 0x10000UL) {
            if (my_disc.upper_ & 0x1000000UL) {
              my_disc.data_ |= 0x1010101010000ULL;
              op_disc.data_ ^= 0x1010101010000ULL;
              count += 5;
            }
          } else if (my_disc.upper_ & 0x10000UL) {
            my_disc.data_ |= 0x10101010000ULL;
            op_disc.data_ ^= 0x10101010000ULL;
            count += 4;
          }
        } else if (my_disc.upper_ & 0x100UL) {
          my_disc.data_ |= 0x101010000ULL;
          op_disc.data_ ^= 0x101010000ULL;
          count += 3;
        }
      } else if (my_disc.upper_ & 0x1UL) {
        my_disc.data_ |= 0x1010000ULL;
        op_disc.data_ ^= 0x1010000ULL;
        count += 2;
      }
    } else if (my_disc.lower_ & 0x1000000UL) {
      my_disc.data_ |= 0x10000ULL;
      op_disc.data_ ^= 0x10000ULL;
      count += 1;
    }
  }
  if (op_disc.lower_ & 0x20000UL) {
    if (op_disc.lower_ & 0x4000000UL) {
      if (op_disc.upper_ & 0x8UL) {
        if (op_disc.upper_ & 0x1000UL) {
          if (op_disc.upper_ & 0x200000UL) {
            if (my_disc.upper_ & 0x40000000UL) {
              my_disc.data_ |= 0x20100804020000ULL;
              op_disc.data_ ^= 0x20100804020000ULL;
              count += 5;
            }
          } else if (my_disc.upper_ & 0x200000UL) {
            my_disc.data_ |= 0x100804020000ULL;
            op_disc.data_ ^= 0x100804020000ULL;
            count += 4;
          }
        } else if (my_disc.upper_ & 0x1000UL) {
          my_disc.data_ |= 0x804020000ULL;
          op_disc.data_ ^= 0x804020000ULL;
          count += 3;
        }
      } else if (my_disc.upper_ & 0x8UL) {
        my_disc.data_ |= 0x4020000ULL;
        op_disc.data_ ^= 0x4020000ULL;
        count += 2;
      }
    } else if (my_disc.lower_ & 0x4000000UL) {
      my_disc.data_ |= 0x20000ULL;
      op_disc.data_ ^= 0x20000ULL;
      count += 1;
    }
  }
  return count;
}

static int f_11(bit_matrix& my_disc, bit_matrix& op_disc) {
  int count = 0;
  if (op_disc.lower_ & 0x400UL) {
    if (op_disc.lower_ & 0x800UL) {
      if (op_disc.lower_ & 0x1000UL) {
        if (op_disc.lower_ & 0x2000UL) {
          if (op_disc.lower_ & 0x4000UL) {
            if (my_disc.lower_ & 0x8000UL) {
              my_disc.data_ |= 0x7c00ULL;
              op_disc.data_ ^= 0x7c00ULL;
              count += 5;
            }
          } else if (my_disc.lower_ & 0x4000UL) {
            my_disc.data_ |= 0x3c00ULL;
            op_disc.data_ ^= 0x3c00ULL;
            count += 4;
          }
        } else if (my_disc.lower_ & 0x2000UL) {
          my_disc.data_ |= 0x1c00ULL;
          op_disc.data_ ^= 0x1c00ULL;
          count += 3;
        }
      } else if (my_disc.lower_ & 0x1000UL) {
        my_disc.data_ |= 0xc00ULL;
        op_disc.data_ ^= 0xc00ULL;
        count += 2;
      }
    } else if (my_disc.lower_ & 0x800UL) {
      my_disc.data_ |= 0x400ULL;
      op_disc.data_ ^= 0x400ULL;
      count += 1;
    }
  }
  if (op_disc.lower_ & 0x20000UL) {
    if (op_disc.lower_ & 0x2000000UL) {
      if (op_disc.upper_ & 0x2UL) {
        if (op_disc.upper_ & 0x200UL) {
          if (op_disc.upper_ & 0x20000UL) {
            if (my_disc.upper_ & 0x2000000UL) {
              my_disc.data_ |= 0x2020202020000ULL;
              op_disc.data_ ^= 0x2020202020000ULL;
              count += 5;
            }
          } else if (my_disc.upper_ & 0x20000UL) {
            my_disc.data_ |= 0x20202020000ULL;
            op_disc.data_ ^= 0x20202020000ULL;
            count += 4;
          }
        } else if (my_disc.upper_ & 0x200UL) {
          my_disc.data_ |= 0x202020000ULL;
          op_disc.data_ ^= 0x202020000ULL;
          count += 3;
        }
      } else if (my_disc.upper_ & 0x2UL) {
        my_disc.data_ |= 0x2020000ULL;
        op_disc.data_ ^= 0x2020000ULL;
        count += 2;
      }
    } else if (my_disc.lower_ & 0x2000000UL) {
      my_disc.data_ |= 0x20000ULL;
      op_disc.data_ ^= 0x20000ULL;
      count += 1;
    }
  }
  if (op_disc.lower_ & 0x40000UL) {
    if (op_disc.lower_ & 0x8000000UL) {
      if (op_disc.upper_ & 0x10UL) {
        if (op_disc.upper_ & 0x2000UL) {
          if (op_disc.upper_ & 0x400000UL) {
            if (my_disc.upper_ & 0x80000000UL) {
              my_disc.data_ |= 0x40201008040000ULL;
              op_disc.data_ ^= 0x40201008040000ULL;
              count += 5;
            }
          } else if (my_disc.upper_ & 0x400000UL) {
            my_disc.data_ |= 0x201008040000ULL;
            op_disc.data_ ^= 0x201008040000ULL;
            count += 4;
          }
        } else if (my_disc.upper_ & 0x2000UL) {
          my_disc.data_ |= 0x1008040000ULL;
          op_disc.data_ ^= 0x1008040000ULL;
          count += 3;
        }
      } else if (my_disc.upper_ & 0x10UL) {
        my_disc.data_ |= 0x8040000ULL;
        op_disc.data_ ^= 0x8040000ULL;
        count += 2;
      }
    } else if (my_disc.lower_ & 0x8000000UL) {
      my_disc.data_ |= 0x40000ULL;
      op_disc.data_ ^= 0x40000ULL;
      count += 1;
    }
  }
  return count;
}

static int f_12(bit_matrix& my_disc, bit_matrix& op_disc) {
  int count = 0;
  if (op_disc.lower_ & 0x800UL) {
    if (op_disc.lower_ & 0x1000UL) {
      if (op_disc.lower_ & 0x2000UL) {
        if (op_disc.lower_ & 0x4000UL) {
          if (my_disc.lower_ & 0x8000UL) {
            my_disc.data_ |= 0x7800ULL;
            op_disc.data_ ^= 0x7800ULL;
            count += 4;
          }
        } else if (my_disc.lower_ & 0x4000UL) {
          my_disc.data_ |= 0x3800ULL;
          op_disc.data_ ^= 0x3800ULL;
          count += 3;
        }
      } else if (my_disc.lower_ & 0x2000UL) {
        my_disc.data_ |= 0x1800ULL;
        op_disc.data_ ^= 0x1800ULL;
        count += 2;
      }
    } else if (my_disc.lower_ & 0x1000UL) {
      my_disc.data_ |= 0x800ULL;
      op_disc.data_ ^= 0x800ULL;
      count += 1;
    }
  }
  if (op_disc.lower_ & 0x200UL) {
    if (my_disc.lower_ & 0x100UL) {
      my_disc.data_ |= 0x200ULL;
      op_disc.data_ ^= 0x200ULL;
      count += 1;
    }
  }
  if (op_disc.lower_ & 0x40000UL) {
    if (op_disc.lower_ & 0x4000000UL) {
      if (op_disc.upper_ & 0x4UL) {
        if (op_disc.upper_ & 0x400UL) {
          if (op_disc.upper_ & 0x40000UL) {
            if (my_disc.upper_ & 0x4000000UL) {
              my_disc.data_ |= 0x4040404040000ULL;
              op_disc.data_ ^= 0x4040404040000ULL;
              count += 5;
            }
          } else if (my_disc.upper_ & 0x40000UL) {
            my_disc.data_ |= 0x40404040000ULL;
            op_disc.data_ ^= 0x40404040000ULL;
            count += 4;
          }
        } else if (my_disc.upper_ & 0x400UL) {
          my_disc.data_ |= 0x404040000ULL;
          op_disc.data_ ^= 0x404040000ULL;
          count += 3;
        }
      } else if (my_disc.upper_ & 0x4UL) {
        my_disc.data_ |= 0x4040000ULL;
        op_disc.data_ ^= 0x4040000ULL;
        count += 2;
      }
    } else if (my_disc.lower_ & 0x4000000UL) {
      my_disc.data_ |= 0x40000ULL;
      op_disc.data_ ^= 0x40000ULL;
      count += 1;
    }
  }
  if (op_disc.lower_ & 0x80000UL) {
    if (op_disc.lower_ & 0x10000000UL) {
      if (op_disc.upper_ & 0x20UL) {
        if (op_disc.upper_ & 0x4000UL) {
          if (my_disc.upper_ & 0x800000UL) {
            my_disc.data_ |= 0x402010080000ULL;
            op_disc.data_ ^= 0x402010080000ULL;
            count += 4;
          }
        } else if (my_disc.upper_ & 0x4000UL) {
          my_disc.data_ |= 0x2010080000ULL;
          op_disc.data_ ^= 0x2010080000ULL;
          count += 3;
        }
      } else if (my_disc.upper_ & 0x20UL) {
        my_disc.data_ |= 0x10080000ULL;
        op_disc.data_ ^= 0x10080000ULL;
        count += 2;
      }
    } else if (my_disc.lower_ & 0x10000000UL) {
      my_disc.data_ |= 0x80000ULL;
      op_disc.data_ ^= 0x80000ULL;
      count += 1;
    }
  }
  if (op_disc.lower_ & 0x20000UL) {
    if (my_disc.lower_ & 0x1000000UL) {
      my_disc.data_ |= 0x20000ULL;
      op_disc.data_ ^= 0x20000ULL;
      count += 1;
    }
  }
  return count;
}

static int f_13(bit_matrix& my_disc, bit_matrix& op_disc) {
  int count = 0;
  if (op_disc.lower_ & 0x1000UL) {
    if (op_disc.lower_ & 0x2000UL) {
      if (op_disc.lower_ & 0x4000UL) {
        if (my_disc.lower_ & 0x8000UL) {
          my_disc.data_ |= 0x7000ULL;
          op_disc.data_ ^= 0x7000ULL;
          count += 3;
        }
      } else if (my_disc.lower_ & 0x4000UL) {
        my_disc.data_ |= 0x3000ULL;
        op_disc.data_ ^= 0x3000ULL;
        count += 2;
      }
    } else if (my_disc.lower_ & 0x2000UL) {
      my_disc.data_ |= 0x1000ULL;
      op_disc.data_ ^= 0x1000ULL;
      count += 1;
    }
  }
  if (op_disc.lower_ & 0x400UL) {
    if (op_disc.lower_ & 0x200UL) {
      if (my_disc.lower_ & 0x100UL) {
        my_disc.data_ |= 0x600ULL;
        op_disc.data_ ^= 0x600ULL;
        count += 2;
      }
    } else if (my_disc.lower_ & 0x200UL) {
      my_disc.data_ |= 0x400ULL;
      op_disc.data_ ^= 0x400ULL;
      count += 1;
    }
  }
  if (op_disc.lower_ & 0x80000UL) {
    if (op_disc.lower_ & 0x8000000UL) {
      if (op_disc.upper_ & 0x8UL) {
        if (op_disc.upper_ & 0x800UL) {
          if (op_disc.upper_ & 0x80000UL) {
            if (my_disc.upper_ & 0x8000000UL) {
              my_disc.data_ |= 0x8080808080000ULL;
              op_disc.data_ ^= 0x8080808080000ULL;
              count += 5;
            }
          } else if (my_disc.upper_ & 0x80000UL) {
            my_disc.data_ |= 0x80808080000ULL;
            op_disc.data_ ^= 0x80808080000ULL;
            count += 4;
          }
        } else if (my_disc.upper_ & 0x800UL) {
          my_disc.data_ |= 0x808080000ULL;
          op_disc.data_ ^= 0x808080000ULL;
          count += 3;
        }
      } else if (my_disc.upper_ & 0x8UL) {
        my_disc.data_ |= 0x8080000ULL;
        op_disc.data_ ^= 0x8080000ULL;
        count += 2;
      }
    } else if (my_disc.lower_ & 0x8000000UL) {
      my_disc.data_ |= 0x80000ULL;
      op_disc.data_ ^= 0x80000ULL;
      count += 1;
    }
  }
  if (op_disc.lower_ & 0x100000UL) {
    if (op_disc.lower_ & 0x20000000UL) {
      if (op_disc.upper_ & 0x40UL) {
        if (my_disc.upper_ & 0x8000UL) {
          my_disc.data_ |= 0x4020100000ULL;
          op_disc.data_ ^= 0x4020100000ULL;
          count += 3;
        }
      } else if (my_disc.upper_ & 0x40UL) {
        my_disc.data_ |= 0x20100000ULL;
        op_disc.data_ ^= 0x20100000ULL;
        count += 2;
      }
    } else if (my_disc.lower_ & 0x20000000UL) {
      my_disc.data_ |= 0x100000ULL;
      op_disc.data_ ^= 0x100000ULL;
      count += 1;
    }
  }
  if (op_disc.lower_ & 0x40000UL) {
    if (op_disc.lower_ & 0x2000000UL) {
      if (my_disc.upper_ & 0x1UL) {
        my_disc.data_ |= 0x2040000ULL;
        op_disc.data_ ^= 0x2040000ULL;
        count += 2;
      }
    } else if (my_disc.lower_ & 0x2000000UL) {
      my_disc.data_ |= 0x40000ULL;
      op_disc.data_ ^= 0x40000ULL;
      count += 1;
    }
  }
  return count;
}

static int f_14(bit_matrix& my_disc, bit_matrix& op_disc) {
  int count = 0;
  if (op_disc.lower_ & 0x2000UL) {
    if (op_disc.lower_ & 0x4000UL) {
      if (my_disc.lower_ & 0x8000UL) {
        my_disc.data_ |= 0x6000ULL;
        op_disc.data_ ^= 0x6000ULL;
        count += 2;
      }
    } else if (my_disc.lower_ & 0x4000UL) {
      my_disc.data_ |= 0x2000ULL;
      op_disc.data_ ^= 0x2000ULL;
      count += 1;
    }
  }
  if (op_disc.lower_ & 0x800UL) {
    if (op_disc.lower_ & 0x400UL) {
      if (op_disc.lower_ & 0x200UL) {
        if (my_disc.lower_ & 0x100UL) {
          my_disc.data_ |= 0xe00ULL;
          op_disc.data_ ^= 0xe00ULL;
          count += 3;
        }
      } else if (my_disc.lower_ & 0x200UL) {
        my_disc.data_ |= 0xc00ULL;
        op_disc.data_ ^= 0xc00ULL;
        count += 2;
      }
    } else if (my_disc.lower_ & 0x400UL) {
      my_disc.data_ |= 0x800ULL;
      op_disc.data_ ^= 0x800ULL;
      count += 1;
    }
  }
  if (op_disc.lower_ & 0x100000UL) {
    if (op_disc.lower_ & 0x10000000UL) {
      if (op_disc.upper_ & 0x10UL) {
        if (op_disc.upper_ & 0x1000UL) {
          if (op_disc.upper_ & 0x100000UL) {
            if (my_disc.upper_ & 0x10000000UL) {
              my_disc.data_ |= 0x10101010100000ULL;
              op_disc.data_ ^= 0x10101010100000ULL;
              count += 5;
            }
          } else if (my_disc.upper_ & 0x100000UL) {
            my_disc.data_ |= 0x101010100000ULL;
            op_disc.data_ ^= 0x101010100000ULL;
            count += 4;
          }
        } else if (my_disc.upper_ & 0x1000UL) {
          my_disc.data_ |= 0x1010100000ULL;
          op_disc.data_ ^= 0x1010100000ULL;
          count += 3;
        }
      } else if (my_disc.upper_ & 0x10UL) {
        my_disc.data_ |= 0x10100000ULL;
        op_disc.data_ ^= 0x10100000ULL;
        count += 2;
      }
    } else if (my_disc.lower_ & 0x10000000UL) {
      my_disc.data_ |= 0x100000ULL;
      op_disc.data_ ^= 0x100000ULL;
      count += 1;
    }
  }
  if (op_disc.lower_ & 0x200000UL) {
    if (op_disc.lower_ & 0x40000000UL) {
      if (my_disc.upper_ & 0x80UL) {
        my_disc.data_ |= 0x40200000ULL;
        op_disc.data_ ^= 0x40200000ULL;
        count += 2;
      }
    } else if (my_disc.lower_ & 0x40000000UL) {
      my_disc.data_ |= 0x200000ULL;
      op_disc.data_ ^= 0x200000ULL;
      count += 1;
    }
  }
  if (op_disc.lower_ & 0x80000UL) {
    if (op_disc.lower_ & 0x4000000UL) {
      if (op_disc.upper_ & 0x2UL) {
        if (my_disc.upper_ & 0x100UL) {
          my_disc.data_ |= 0x204080000ULL;
          op_disc.data_ ^= 0x204080000ULL;
          count += 3;
        }
      } else if (my_disc.upper_ & 0x2UL) {
        my_disc.data_ |= 0x4080000ULL;
        op_disc.data_ ^= 0x4080000ULL;
        count += 2;
      }
    } else if (my_disc.lower_ & 0x4000000UL) {
      my_disc.data_ |= 0x80000ULL;
      op_disc.data_ ^= 0x80000ULL;
      count += 1;
    }
  }
  return count;
}

static int f_15(bit_matrix& my_disc, bit_matrix& op_disc) {
  int count = 0;
  if (op_disc.lower_ & 0x4000UL) {
    if (my_disc.lower_ & 0x8000UL) {
      my_disc.data_ |= 0x4000ULL;
      op_disc.data_ ^= 0x4000ULL;
      count += 1;
    }
  }
  if (op_disc.lower_ & 0x1000UL) {
    if (op_disc.lower_ & 0x800UL) {
      if (op_disc.lower_ & 0x400UL) {
        if (op_disc.lower_ & 0x200UL) {
          if (my_disc.lower_ & 0x100UL) {
            my_disc.data_ |= 0x1e00ULL;
            op_disc.data_ ^= 0x1e00ULL;
            count += 4;
          }
        } else if (my_disc.lower_ & 0x200UL) {
          my_disc.data_ |= 0x1c00ULL;
          op_disc.data_ ^= 0x1c00ULL;
          count += 3;
        }
      } else if (my_disc.lower_ & 0x400UL) {
        my_disc.data_ |= 0x1800ULL;
        op_disc.data_ ^= 0x1800ULL;
        count += 2;
      }
    } else if (my_disc.lower_ & 0x800UL) {
      my_disc.data_ |= 0x1000ULL;
      op_disc.data_ ^= 0x1000ULL;
      count += 1;
    }
  }
  if (op_disc.lower_ & 0x200000UL) {
    if (op_disc.lower_ & 0x20000000UL) {
      if (op_disc.upper_ & 0x20UL) {
        if (op_disc.upper_ & 0x2000UL) {
          if (op_disc.upper_ & 0x200000UL) {
            if (my_disc.upper_ & 0x20000000UL) {
              my_disc.data_ |= 0x20202020200000ULL;
              op_disc.data_ ^= 0x20202020200000ULL;
              count += 5;
            }
          } else if (my_disc.upper_ & 0x200000UL) {
            my_disc.data_ |= 0x202020200000ULL;
            op_disc.data_ ^= 0x202020200000ULL;
            count += 4;
          }
        } else if (my_disc.upper_ & 0x2000UL) {
          my_disc.data_ |= 0x2020200000ULL;
          op_disc.data_ ^= 0x2020200000ULL;
          count += 3;
        }
      } else if (my_disc.upper_ & 0x20UL) {
        my_disc.data_ |= 0x20200000ULL;
        op_disc.data_ ^= 0x20200000ULL;
        count += 2;
      }
    } else if (my_disc.lower_ & 0x20000000UL) {
      my_disc.data_ |= 0x200000ULL;
      op_disc.data_ ^= 0x200000ULL;
      count += 1;
    }
  }
  if (op_disc.lower_ & 0x400000UL) {
    if (my_disc.lower_ & 0x80000000UL) {
      my_disc.data_ |= 0x400000ULL;
      op_disc.data_ ^= 0x400000ULL;
      count += 1;
    }
  }
  if (op_disc.lower_ & 0x100000UL) {
    if (op_disc.lower_ & 0x8000000UL) {
      if (op_disc.upper_ & 0x4UL) {
        if (op_disc.upper_ & 0x200UL) {
          if (my_disc.upper_ & 0x10000UL) {
            my_disc.data_ |= 0x20408100000ULL;
            op_disc.data_ ^= 0x20408100000ULL;
            count += 4;
          }
        } else if (my_disc.upper_ & 0x200UL) {
          my_disc.data_ |= 0x408100000ULL;
          op_disc.data_ ^= 0x408100000ULL;
          count += 3;
        }
      } else if (my_disc.upper_ & 0x4UL) {
        my_disc.data_ |= 0x8100000ULL;
        op_disc.data_ ^= 0x8100000ULL;
        count += 2;
      }
    } else if (my_disc.lower_ & 0x8000000UL) {
      my_disc.data_ |= 0x100000ULL;
      op_disc.data_ ^= 0x100000ULL;
      count += 1;
    }
  }
  return count;
}

static int f_16(bit_matrix& my_disc, bit_matrix& op_disc) {
  int count = 0;
  if (op_disc.lower_ & 0x2000UL) {
    if (op_disc.lower_ & 0x1000UL) {
      if (op_disc.lower_ & 0x800UL) {
        if (op_disc.lower_ & 0x400UL) {
          if (op_disc.lower_ & 0x200UL) {
            if (my_disc.lower_ & 0x100UL) {
              my_disc.data_ |= 0x3e00ULL;
              op_disc.data_ ^= 0x3e00ULL;
              count += 5;
            }
          } else if (my_disc.lower_ & 0x200UL) {
            my_disc.data_ |= 0x3c00ULL;
            op_disc.data_ ^= 0x3c00ULL;
            count += 4;
          }
        } else if (my_disc.lower_ & 0x400UL) {
          my_disc.data_ |= 0x3800ULL;
          op_disc.data_ ^= 0x3800ULL;
          count += 3;
        }
      } else if (my_disc.lower_ & 0x800UL) {
        my_disc.data_ |= 0x3000ULL;
        op_disc.data_ ^= 0x3000ULL;
        count += 2;
      }
    } else if (my_disc.lower_ & 0x1000UL) {
      my_disc.data_ |= 0x2000ULL;
      op_disc.data_ ^= 0x2000ULL;
      count += 1;
    }
  }
  if (op_disc.lower_ & 0x400000UL) {
    if (op_disc.lower_ & 0x40000000UL) {
      if (op_disc.upper_ & 0x40UL) {
        if (op_disc.upper_ & 0x4000UL) {
          if (op_disc.upper_ & 0x400000UL) {
            if (my_disc.upper_ & 0x40000000UL) {
              my_disc.data_ |= 0x40404040400000ULL;
              op_disc.data_ ^= 0x40404040400000ULL;
              count += 5;
            }
          } else if (my_disc.upper_ & 0x400000UL) {
            my_disc.data_ |= 0x404040400000ULL;
            op_disc.data_ ^= 0x404040400000ULL;
            count += 4;
          }
        } else if (my_disc.upper_ & 0x4000UL) {
          my_disc.data_ |= 0x4040400000ULL;
          op_disc.data_ ^= 0x4040400000ULL;
          count += 3;
        }
      } else if (my_disc.upper_ & 0x40UL) {
        my_disc.data_ |= 0x40400000ULL;
        op_disc.data_ ^= 0x40400000ULL;
        count += 2;
      }
    } else if (my_disc.lower_ & 0x40000000UL) {
      my_disc.data_ |= 0x400000ULL;
      op_disc.data_ ^= 0x400000ULL;
      count += 1;
    }
  }
  if (op_disc.lower_ & 0x200000UL) {
    if (op_disc.lower_ & 0x10000000UL) {
      if (op_disc.upper_ & 0x8UL) {
        if (op_disc.upper_ & 0x400UL) {
          if (op_disc.upper_ & 0x20000UL) {
            if (my_disc.upper_ & 0x1000000UL) {
              my_disc.data_ |= 0x2040810200000ULL;
              op_disc.data_ ^= 0x2040810200000ULL;
              count += 5;
            }
          } else if (my_disc.upper_ & 0x20000UL) {
            my_disc.data_ |= 0x40810200000ULL;
            op_disc.data_ ^= 0x40810200000ULL;
            count += 4;
          }
        } else if (my_disc.upper_ & 0x400UL) {
          my_disc.data_ |= 0x810200000ULL;
          op_disc.data_ ^= 0x810200000ULL;
          count += 3;
        }
      } else if (my_disc.upper_ & 0x8UL) {
        my_disc.data_ |= 0x10200000ULL;
        op_disc.data_ ^= 0x10200000ULL;
        count += 2;
      }
    } else if (my_disc.lower_ & 0x10000000UL) {
      my_disc.data_ |= 0x200000ULL;
      op_disc.data_ ^= 0x200000ULL;
      count += 1;
    }
  }
  return count;
}

static int f_17(bit_matrix& my_disc, bit_matrix& op_disc) {
  int count = 0;
  if (op_disc.lower_ & 0x4000UL) {
    if (op_disc.lower_ & 0x2000UL) {
      if (op_disc.lower_ & 0x1000UL) {
        if (op_disc.lower_ & 0x800UL) {
          if (op_disc.lower_ & 0x400UL) {
            if (op_disc.lower_ & 0x200UL) {
              if (my_disc.lower_ & 0x100UL) {
                my_disc.data_ |= 0x7e00ULL;
                op_disc.data_ ^= 0x7e00ULL;
                count += 6;
              }
            } else if (my_disc.lower_ & 0x200UL) {
              my_disc.data_ |= 0x7c00ULL;
              op_disc.data_ ^= 0x7c00ULL;
              count += 5;
            }
          } else if (my_disc.lower_ & 0x400UL) {
            my_disc.data_ |= 0x7800ULL;
            op_disc.data_ ^= 0x7800ULL;
            count += 4;
          }
        } else if (my_disc.lower_ & 0x800UL) {
          my_disc.data_ |= 0x7000ULL;
          op_disc.data_ ^= 0x7000ULL;
          count += 3;
        }
      } else if (my_disc.lower_ & 0x1000UL) {
        my_disc.data_ |= 0x6000ULL;
        op_disc.data_ ^= 0x6000ULL;
        count += 2;
      }
    } else if (my_disc.lower_ & 0x2000UL) {
      my_disc.data_ |= 0x4000ULL;
      op_disc.data_ ^= 0x4000ULL;
      count += 1;
    }
  }
  if (op_disc.lower_ & 0x800000UL) {
    if (op_disc.lower_ & 0x80000000UL) {
      if (op_disc.upper_ & 0x80UL) {
        if (op_disc.upper_ & 0x8000UL) {
          if (op_disc.upper_ & 0x800000UL) {
            if (my_disc.upper_ & 0x80000000UL) {
              my_disc.data_ |= 0x80808080800000ULL;
              op_disc.data_ ^= 0x80808080800000ULL;
              count += 5;
            }
          } else if (my_disc.upper_ & 0x800000UL) {
            my_disc.data_ |= 0x808080800000ULL;
            op_disc.data_ ^= 0x808080800000ULL;
            count += 4;
          }
        } else if (my_disc.upper_ & 0x8000UL) {
          my_disc.data_ |= 0x8080800000ULL;
          op_disc.data_ ^= 0x8080800000ULL;
          count += 3;
        }
      } else if (my_disc.upper_ & 0x80UL) {
        my_disc.data_ |= 0x80800000ULL;
        op_disc.data_ ^= 0x80800000ULL;
        count += 2;
      }
    } else if (my_disc.lower_ & 0x80000000UL) {
      my_disc.data_ |= 0x800000ULL;
      op_disc.data_ ^= 0x800000ULL;
      count += 1;
    }
  }
  if (op_disc.lower_ & 0x400000UL) {
    if (op_disc.lower_ & 0x20000000UL) {
      if (op_disc.upper_ & 0x10UL) {
        if (op_disc.upper_ & 0x800UL) {
          if (op_disc.upper_ & 0x40000UL) {
            if (my_disc.upper_ & 0x2000000UL) {
              my_disc.data_ |= 0x4081020400000ULL;
              op_disc.data_ ^= 0x4081020400000ULL;
              count += 5;
            }
          } else if (my_disc.upper_ & 0x40000UL) {
            my_disc.data_ |= 0x81020400000ULL;
            op_disc.data_ ^= 0x81020400000ULL;
            count += 4;
          }
        } else if (my_disc.upper_ & 0x800UL) {
          my_disc.data_ |= 0x1020400000ULL;
          op_disc.data_ ^= 0x1020400000ULL;
          count += 3;
        }
      } else if (my_disc.upper_ & 0x10UL) {
        my_disc.data_ |= 0x20400000ULL;
        op_disc.data_ ^= 0x20400000ULL;
        count += 2;
      }
    } else if (my_disc.lower_ & 0x20000000UL) {
      my_disc.data_ |= 0x400000ULL;
      op_disc.data_ ^= 0x400000ULL;
      count += 1;
    }
  }
  return count;
}

static int f_20(bit_matrix& my_disc, bit_matrix& op_disc) {
  int count = 0;
  if (op_disc.lower_ & 0x20000UL) {
    if (op_disc.lower_ & 0x40000UL) {
      if (op_disc.lower_ & 0x80000UL) {
        if (op_disc.lower_ & 0x100000UL) {
          if (op_disc.lower_ & 0x200000UL) {
            if (op_disc.lower_ & 0x400000UL) {
              if (my_disc.lower_ & 0x800000UL) {
                my_disc.data_ |= 0x7e0000ULL;
                op_disc.data_ ^= 0x7e0000ULL;
                count += 6;
              }
            } else if (my_disc.lower_ & 0x400000UL) {
              my_disc.data_ |= 0x3e0000ULL;
              op_disc.data_ ^= 0x3e0000ULL;
              count += 5;
            }
          } else if (my_disc.lower_ & 0x200000UL) {
            my_disc.data_ |= 0x1e0000ULL;
            op_disc.data_ ^= 0x1e0000ULL;
            count += 4;
          }
        } else if (my_disc.lower_ & 0x100000UL) {
          my_disc.data_ |= 0xe0000ULL;
          op_disc.data_ ^= 0xe0000ULL;
          count += 3;
        }
      } else if (my_disc.lower_ & 0x80000UL) {
        my_disc.data_ |= 0x60000ULL;
        op_disc.data_ ^= 0x60000ULL;
        count += 2;
      }
    } else if (my_disc.lower_ & 0x40000UL) {
      my_disc.data_ |= 0x20000ULL;
      op_disc.data_ ^= 0x20000ULL;
      count += 1;
    }
  }
  if (op_disc.lower_ & 0x1000000UL) {
    if (op_disc.upper_ & 0x1UL) {
      if (op_disc.upper_ & 0x100UL) {
        if (op_disc.upper_ & 0x10000UL) {
          if (my_disc.upper_ & 0x1000000UL) {
            my_disc.data_ |= 0x1010101000000ULL;
            op_disc.data_ ^= 0x1010101000000ULL;
            count += 4;
          }
        } else if (my_disc.upper_ & 0x10000UL) {
          my_disc.data_ |= 0x10101000000ULL;
          op_disc.data_ ^= 0x10101000000ULL;
          count += 3;
        }
      } else if (my_disc.upper_ & 0x100UL) {
        my_disc.data_ |= 0x101000000ULL;
        op_disc.data_ ^= 0x101000000ULL;
        count += 2;
      }
    } else if (my_disc.upper_ & 0x1UL) {
      my_disc.data_ |= 0x1000000ULL;
      op_disc.data_ ^= 0x1000000ULL;
      count += 1;
    }
  }
  if (op_disc.lower_ & 0x100UL) {
    if (my_disc.lower_ & 0x1UL) {
      my_disc.data_ |= 0x100ULL;
      op_disc.data_ ^= 0x100ULL;
      count += 1;
    }
  }
  if (op_disc.lower_ & 0x2000000UL) {
    if (op_disc.upper_ & 0x4UL) {
      if (op_disc.upper_ & 0x800UL) {
        if (op_disc.upper_ & 0x100000UL) {
          if (my_disc.upper_ & 0x20000000UL) {
            my_disc.data_ |= 0x10080402000000ULL;
            op_disc.data_ ^= 0x10080402000000ULL;
            count += 4;
          }
        } else if (my_disc.upper_ & 0x100000UL) {
          my_disc.data_ |= 0x80402000000ULL;
          op_disc.data_ ^= 0x80402000000ULL;
          count += 3;
        }
      } else if (my_disc.upper_ & 0x800UL) {
        my_disc.data_ |= 0x402000000ULL;
        op_disc.data_ ^= 0x402000000ULL;
        count += 2;
      }
    } else if (my_disc.upper_ & 0x4UL) {
      my_disc.data_ |= 0x2000000ULL;
      op_disc.data_ ^= 0x2000000ULL;
      count += 1;
    }
  }
  if (op_disc.lower_ & 0x200UL) {
    if (my_disc.lower_ & 0x4UL) {
      my_disc.data_ |= 0x200ULL;
      op_disc.data_ ^= 0x200ULL;
      count += 1;
    }
  }
  return count;
}

static int f_21(bit_matrix& my_disc, bit_matrix& op_disc) {
  int count = 0;
  if (op_disc.lower_ & 0x40000UL) {
    if (op_disc.lower_ & 0x80000UL) {
      if (op_disc.lower_ & 0x100000UL) {
        if (op_disc.lower_ & 0x200000UL) {
          if (op_disc.lower_ & 0x400000UL) {
            if (my_disc.lower_ & 0x800000UL) {
              my_disc.data_ |= 0x7c0000ULL;
              op_disc.data_ ^= 0x7c0000ULL;
              count += 5;
            }
          } else if (my_disc.lower_ & 0x400000UL) {
            my_disc.data_ |= 0x3c0000ULL;
            op_disc.data_ ^= 0x3c0000ULL;
            count += 4;
          }
        } else if (my_disc.lower_ & 0x200000UL) {
          my_disc.data_ |= 0x1c0000ULL;
          op_disc.data_ ^= 0x1c0000ULL;
          count += 3;
        }
      } else if (my_disc.lower_ & 0x100000UL) {
        my_disc.data_ |= 0xc0000ULL;
        op_disc.data_ ^= 0xc0000ULL;
        count += 2;
      }
    } else if (my_disc.lower_ & 0x80000UL) {
      my_disc.data_ |= 0x40000ULL;
      op_disc.data_ ^= 0x40000ULL;
      count += 1;
    }
  }
  if (op_disc.lower_ & 0x2000000UL) {
    if (op_disc.upper_ & 0x2UL) {
      if (op_disc.upper_ & 0x200UL) {
        if (op_disc.upper_ & 0x20000UL) {
          if (my_disc.upper_ & 0x2000000UL) {
            my_disc.data_ |= 0x2020202000000ULL;
            op_disc.data_ ^= 0x2020202000000ULL;
            count += 4;
          }
        } else if (my_disc.upper_ & 0x20000UL) {
          my_disc.data_ |= 0x20202000000ULL;
          op_disc.data_ ^= 0x20202000000ULL;
          count += 3;
        }
      } else if (my_disc.upper_ & 0x200UL) {
        my_disc.data_ |= 0x202000000ULL;
        op_disc.data_ ^= 0x202000000ULL;
        count += 2;
      }
    } else if (my_disc.upper_ & 0x2UL) {
      my_disc.data_ |= 0x2000000ULL;
      op_disc.data_ ^= 0x2000000ULL;
      count += 1;
    }
  }
  if (op_disc.lower_ & 0x200UL) {
    if (my_disc.lower_ & 0x2UL) {
      my_disc.data_ |= 0x200ULL;
      op_disc.data_ ^= 0x200ULL;
      count += 1;
    }
  }
  if (op_disc.lower_ & 0x4000000UL) {
    if (op_disc.upper_ & 0x8UL) {
      if (op_disc.upper_ & 0x1000UL) {
        if (op_disc.upper_ & 0x200000UL) {
          if (my_disc.upper_ & 0x40000000UL) {
            my_disc.data_ |= 0x20100804000000ULL;
            op_disc.data_ ^= 0x20100804000000ULL;
            count += 4;
          }
        } else if (my_disc.upper_ & 0x200000UL) {
          my_disc.data_ |= 0x100804000000ULL;
          op_disc.data_ ^= 0x100804000000ULL;
          count += 3;
        }
      } else if (my_disc.upper_ & 0x1000UL) {
        my_disc.data_ |= 0x804000000ULL;
        op_disc.data_ ^= 0x804000000ULL;
        count += 2;
      }
    } else if (my_disc.upper_ & 0x8UL) {
      my_disc.data_ |= 0x4000000ULL;
      op_disc.data_ ^= 0x4000000ULL;
      count += 1;
    }
  }
  if (op_disc.lower_ & 0x400UL) {
    if (my_disc.lower_ & 0x8UL) {
      my_disc.data_ |= 0x400ULL;
      op_disc.data_ ^= 0x400ULL;
      count += 1;
    }
  }
  return count;
}

static int f_22(bit_matrix& my_disc, bit_matrix& op_disc) {
  int count = 0;
  if (op_disc.lower_ & 0x80000UL) {
    if (op_disc.lower_ & 0x100000UL) {
      if (op_disc.lower_ & 0x200000UL) {
        if (op_disc.lower_ & 0x400000UL) {
          if (my_disc.lower_ & 0x800000UL) {
            my_disc.data_ |= 0x780000ULL;
            op_disc.data_ ^= 0x780000ULL;
            count += 4;
          }
        } else if (my_disc.lower_ & 0x400000UL) {
          my_disc.data_ |= 0x380000ULL;
          op_disc.data_ ^= 0x380000ULL;
          count += 3;
        }
      } else if (my_disc.lower_ & 0x200000UL) {
        my_disc.data_ |= 0x180000ULL;
        op_disc.data_ ^= 0x180000ULL;
        count += 2;
      }
    } else if (my_disc.lower_ & 0x100000UL) {
      my_disc.data_ |= 0x80000ULL;
      op_disc.data_ ^= 0x80000ULL;
      count += 1;
    }
  }
  if (op_disc.lower_ & 0x20000UL) {
    if (my_disc.lower_ & 0x10000UL) {
      my_disc.data_ |= 0x20000ULL;
      op_disc.data_ ^= 0x20000ULL;
      count += 1;
    }
  }
  if (op_disc.lower_ & 0x4000000UL) {
    if (op_disc.upper_ & 0x4UL) {
      if (op_disc.upper_ & 0x400UL) {
        if (op_disc.upper_ & 0x40000UL) {
          if (my_disc.upper_ & 0x4000000UL) {
            my_disc.data_ |= 0x4040404000000ULL;
            op_disc.data_ ^= 0x4040404000000ULL;
            count += 4;
          }
        } else if (my_disc.upper_ & 0x40000UL) {
          my_disc.data_ |= 0x40404000000ULL;
          op_disc.data_ ^= 0x40404000000ULL;
          count += 3;
        }
      } else if (my_disc.upper_ & 0x400UL) {
        my_disc.data_ |= 0x404000000ULL;
        op_disc.data_ ^= 0x404000000ULL;
        count += 2;
      }
    } else if (my_disc.upper_ & 0x4UL) {
      my_disc.data_ |= 0x4000000ULL;
      op_disc.data_ ^= 0x4000000ULL;
      count += 1;
    }
  }
  if (op_disc.lower_ & 0x400UL) {
    if (my_disc.lower_ & 0x4UL) {
      my_disc.data_ |= 0x400ULL;
      op_disc.data_ ^= 0x400ULL;
      count += 1;
    }
  }
  if (op_disc.lower_ & 0x8000000UL) {
    if (op_disc.upper_ & 0x10UL) {
      if (op_disc.upper_ & 0x2000UL) {
        if (op_disc.upper_ & 0x400000UL) {
          if (my_disc.upper_ & 0x80000000UL) {
            my_disc.data_ |= 0x40201008000000ULL;
            op_disc.data_ ^= 0x40201008000000ULL;
            count += 4;
          }
        } else if (my_disc.upper_ & 0x400000UL) {
          my_disc.data_ |= 0x201008000000ULL;
          op_disc.data_ ^= 0x201008000000ULL;
          count += 3;
        }
      } else if (my_disc.upper_ & 0x2000UL) {
        my_disc.data_ |= 0x1008000000ULL;
        op_disc.data_ ^= 0x1008000000ULL;
        count += 2;
      }
    } else if (my_disc.upper_ & 0x10UL) {
      my_disc.data_ |= 0x8000000ULL;
      op_disc.data_ ^= 0x8000000ULL;
      count += 1;
    }
  }
  if (op_disc.lower_ & 0x800UL) {
    if (my_disc.lower_ & 0x10UL) {
      my_disc.data_ |= 0x800ULL;
      op_disc.data_ ^= 0x800ULL;
      count += 1;
    }
  }
  if (op_disc.lower_ & 0x2000000UL) {
    if (my_disc.upper_ & 0x1UL) {
      my_disc.data_ |= 0x2000000ULL;
      op_disc.data_ ^= 0x2000000ULL;
      count += 1;
    }
  }
  if (op_disc.lower_ & 0x200UL) {
    if (my_disc.lower_ & 0x1UL) {
      my_disc.data_ |= 0x200ULL;
      op_disc.data_ ^= 0x200ULL;
      count += 1;
    }
  }
  return count;
}

static int f_23(bit_matrix& my_disc, bit_matrix& op_disc) {
  int count = 0;
  if (op_disc.lower_ & 0x100000UL) {
    if (op_disc.lower_ & 0x200000UL) {
      if (op_disc.lower_ & 0x400000UL) {
        if (my_disc.lower_ & 0x800000UL) {
          my_disc.data_ |= 0x700000ULL;
          op_disc.data_ ^= 0x700000ULL;
          count += 3;
        }
      } else if (my_disc.lower_ & 0x400000UL) {
        my_disc.data_ |= 0x300000ULL;
        op_disc.data_ ^= 0x300000ULL;
        count += 2;
      }
    } else if (my_disc.lower_ & 0x200000UL) {
      my_disc.data_ |= 0x100000ULL;
      op_disc.data_ ^= 0x100000ULL;
      count += 1;
    }
  }
  if (op_disc.lower_ & 0x40000UL) {
    if (op_disc.lower_ & 0x20000UL) {
      if (my_disc.lower_ & 0x10000UL) {
        my_disc.data_ |= 0x60000ULL;
        op_disc.data_ ^= 0x60000ULL;
        count += 2;
      }
    } else if (my_disc.lower_ & 0x20000UL) {
      my_disc.data_ |= 0x40000ULL;
      op_disc.data_ ^= 0x40000ULL;
      count += 1;
    }
  }
  if (op_disc.lower_ & 0x8000000UL) {
    if (op_disc.upper_ & 0x8UL) {
      if (op_disc.upper_ & 0x800UL) {
        if (op_disc.upper_ & 0x80000UL) {
          if (my_disc.upper_ & 0x8000000UL) {
            my_disc.data_ |= 0x8080808000000ULL;
            op_disc.data_ ^= 0x8080808000000ULL;
            count += 4;
          }
        } else if (my_disc.upper_ & 0x80000UL) {
          my_disc.data_ |= 0x80808000000ULL;
          op_disc.data_ ^= 0x80808000000ULL;
          count += 3;
        }
      } else if (my_disc.upper_ & 0x800UL) {
        my_disc.data_ |= 0x808000000ULL;
        op_disc.data_ ^= 0x808000000ULL;
        count += 2;
      }
    } else if (my_disc.upper_ & 0x8UL) {
      my_disc.data_ |= 0x8000000ULL;
      op_disc.data_ ^= 0x8000000ULL;
      count += 1;
    }
  }
  if (op_disc.lower_ & 0x800UL) {
    if (my_disc.lower_ & 0x8UL) {
      my_disc.data_ |= 0x800ULL;
      op_disc.data_ ^= 0x800ULL;
      count += 1;
    }
  }
  if (op_disc.lower_ & 0x10000000UL) {
    if (op_disc.upper_ & 0x20UL) {
      if (op_disc.upper_ & 0x4000UL) {
        if (my_disc.upper_ & 0x800000UL) {
          my_disc.data_ |= 0x402010000000ULL;
          op_disc.data_ ^= 0x402010000000ULL;
          count += 3;
        }
      } else if (my_disc.upper_ & 0x4000UL) {
        my_disc.data_ |= 0x2010000000ULL;
        op_disc.data_ ^= 0x2010000000ULL;
        count += 2;
      }
    } else if (my_disc.upper_ & 0x20UL) {
      my_disc.data_ |= 0x10000000ULL;
      op_disc.data_ ^= 0x10000000ULL;
      count += 1;
    }
  }
  if (op_disc.lower_ & 0x1000UL) {
    if (my_disc.lower_ & 0x20UL) {
      my_disc.data_ |= 0x1000ULL;
      op_disc.data_ ^= 0x1000ULL;
      count += 1;
    }
  }
  if (op_disc.lower_ & 0x4000000UL) {
    if (op_disc.upper_ & 0x2UL) {
      if (my_disc.upper_ & 0x100UL) {
        my_disc.data_ |= 0x204000000ULL;
        op_disc.data_ ^= 0x204000000ULL;
        count += 2;
      }
    } else if (my_disc.upper_ & 0x2UL) {
      my_disc.data_ |= 0x4000000ULL;
      op_disc.data_ ^= 0x4000000ULL;
      count += 1;
    }
  }
  if (op_disc.lower_ & 0x400UL) {
    if (my_disc.lower_ & 0x2UL) {
      my_disc.data_ |= 0x400ULL;
      op_disc.data_ ^= 0x400ULL;
      count += 1;
    }
  }
  return count;
}

static int f_24(bit_matrix& my_disc, bit_matrix& op_disc) {
  int count = 0;
  if (op_disc.lower_ & 0x200000UL) {
    if (op_disc.lower_ & 0x400000UL) {
      if (my_disc.lower_ & 0x800000UL) {
        my_disc.data_ |= 0x600000ULL;
        op_disc.data_ ^= 0x600000ULL;
        count += 2;
      }
    } else if (my_disc.lower_ & 0x400000UL) {
      my_disc.data_ |= 0x200000ULL;
      op_disc.data_ ^= 0x200000ULL;
      count += 1;
    }
  }
  if (op_disc.lower_ & 0x80000UL) {
    if (op_disc.lower_ & 0x40000UL) {
      if (op_disc.lower_ & 0x20000UL) {
        if (my_disc.lower_ & 0x10000UL) {
          my_disc.data_ |= 0xe0000ULL;
          op_disc.data_ ^= 0xe0000ULL;
          count += 3;
        }
      } else if (my_disc.lower_ & 0x20000UL) {
        my_disc.data_ |= 0xc0000ULL;
        op_disc.data_ ^= 0xc0000ULL;
        count += 2;
      }
    } else if (my_disc.lower_ & 0x40000UL) {
      my_disc.data_ |= 0x80000ULL;
      op_disc.data_ ^= 0x80000ULL;
      count += 1;
    }
  }
  if (op_disc.lower_ & 0x10000000UL) {
    if (op_disc.upper_ & 0x10UL) {
      if (op_disc.upper_ & 0x1000UL) {
        if (op_disc.upper_ & 0x100000UL) {
          if (my_disc.upper_ & 0x10000000UL) {
            my_disc.data_ |= 0x10101010000000ULL;
            op_disc.data_ ^= 0x10101010000000ULL;
            count += 4;
          }
        } else if (my_disc.upper_ & 0x100000UL) {
          my_disc.data_ |= 0x101010000000ULL;
          op_disc.data_ ^= 0x101010000000ULL;
          count += 3;
        }
      } else if (my_disc.upper_ & 0x1000UL) {
        my_disc.data_ |= 0x1010000000ULL;
        op_disc.data_ ^= 0x1010000000ULL;
        count += 2;
      }
    } else if (my_disc.upper_ & 0x10UL) {
      my_disc.data_ |= 0x10000000ULL;
      op_disc.data_ ^= 0x10000000ULL;
      count += 1;
    }
  }
  if (op_disc.lower_ & 0x1000UL) {
    if (my_disc.lower_ & 0x10UL) {
      my_disc.data_ |= 0x1000ULL;
      op_disc.data_ ^= 0x1000ULL;
      count += 1;
    }
  }
  if (op_disc.lower_ & 0x20000000UL) {
    if (op_disc.upper_ & 0x40UL) {
      if (my_disc.upper_ & 0x8000UL) {
        my_disc.data_ |= 0x4020000000ULL;
        op_disc.data_ ^= 0x4020000000ULL;
        count += 2;
      }
    } else if (my_disc.upper_ & 0x40UL) {
      my_disc.data_ |= 0x20000000ULL;
      op_disc.data_ ^= 0x20000000ULL;
      count += 1;
    }
  }
  if (op_disc.lower_ & 0x2000UL) {
    if (my_disc.lower_ & 0x40UL) {
      my_disc.data_ |= 0x2000ULL;
      op_disc.data_ ^= 0x2000ULL;
      count += 1;
    }
  }
  if (op_disc.lower_ & 0x8000000UL) {
    if (op_disc.upper_ & 0x4UL) {
      if (op_disc.upper_ & 0x200UL) {
        if (my_disc.upper_ & 0x10000UL) {
          my_disc.data_ |= 0x20408000000ULL;
          op_disc.data_ ^= 0x20408000000ULL;
          count += 3;
        }
      } else if (my_disc.upper_ & 0x200UL) {
        my_disc.data_ |= 0x408000000ULL;
        op_disc.data_ ^= 0x408000000ULL;
        count += 2;
      }
    } else if (my_disc.upper_ & 0x4UL) {
      my_disc.data_ |= 0x8000000ULL;
      op_disc.data_ ^= 0x8000000ULL;
      count += 1;
    }
  }
  if (op_disc.lower_ & 0x800UL) {
    if (my_disc.lower_ & 0x4UL) {
      my_disc.data_ |= 0x800ULL;
      op_disc.data_ ^= 0x800ULL;
      count += 1;
    }
  }
  return count;
}

static int f_25(bit_matrix& my_disc, bit_matrix& op_disc) {
  int count = 0;
  if (op_disc.lower_ & 0x400000UL) {
    if (my_disc.lower_ & 0x800000UL) {
      my_disc.data_ |= 0x400000ULL;
      op_disc.data_ ^= 0x400000ULL;
      count += 1;
    }
  }
  if (op_disc.lower_ & 0x100000UL) {
    if (op_disc.lower_ & 0x80000UL) {
      if (op_disc.lower_ & 0x40000UL) {
        if (op_disc.lower_ & 0x20000UL) {
          if (my_disc.lower_ & 0x10000UL) {
            my_disc.data_ |= 0x1e0000ULL;
            op_disc.data_ ^= 0x1e0000ULL;
            count += 4;
          }
        } else if (my_disc.lower_ & 0x20000UL) {
          my_disc.data_ |= 0x1c0000ULL;
          op_disc.data_ ^= 0x1c0000ULL;
          count += 3;
        }
      } else if (my_disc.lower_ & 0x40000UL) {
        my_disc.data_ |= 0x180000ULL;
        op_disc.data_ ^= 0x180000ULL;
        count += 2;
      }
    } else if (my_disc.lower_ & 0x80000UL) {
      my_disc.data_ |= 0x100000ULL;
      op_disc.data_ ^= 0x100000ULL;
      count += 1;
    }
  }
  if (op_disc.lower_ & 0x20000000UL) {
    if (op_disc.upper_ & 0x20UL) {
      if (op_disc.upper_ & 0x2000UL) {
        if (op_disc.upper_ & 0x200000UL) {
          if (my_disc.upper_ & 0x20000000UL) {
            my_disc.data_ |= 0x20202020000000ULL;
            op_disc.data_ ^= 0x20202020000000ULL;
            count += 4;
          }
        } else if (my_disc.upper_ & 0x200000UL) {
          my_disc.data_ |= 0x202020000000ULL;
          op_disc.data_ ^= 0x202020000000ULL;
          count += 3;
        }
      } else if (my_disc.upper_ & 0x2000UL) {
        my_disc.data_ |= 0x2020000000ULL;
        op_disc.data_ ^= 0x2020000000ULL;
        count += 2;
      }
    } else if (my_disc.upper_ & 0x20UL) {
      my_disc.data_ |= 0x20000000ULL;
      op_disc.data_ ^= 0x20000000ULL;
      count += 1;
    }
  }
  if (op_disc.lower_ & 0x2000UL) {
    if (my_disc.lower_ & 0x20UL) {
      my_disc.data_ |= 0x2000ULL;
      op_disc.data_ ^= 0x2000ULL;
      count += 1;
    }
  }
  if (op_disc.lower_ & 0x40000000UL) {
    if (my_disc.upper_ & 0x80UL) {
      my_disc.data_ |= 0x40000000ULL;
      op_disc.data_ ^= 0x40000000ULL;
      count += 1;
    }
  }
  if (op_disc.lower_ & 0x4000UL) {
    if (my_disc.lower_ & 0x80UL) {
      my_disc.data_ |= 0x4000ULL;
      op_disc.data_ ^= 0x4000ULL;
      count += 1;
    }
  }
  if (op_disc.lower_ & 0x10000000UL) {
    if (op_disc.upper_ & 0x8UL) {
      if (op_disc.upper_ & 0x400UL) {
        if (op_disc.upper_ & 0x20000UL) {
          if (my_disc.upper_ & 0x1000000UL) {
            my_disc.data_ |= 0x2040810000000ULL;
            op_disc.data_ ^= 0x2040810000000ULL;
            count += 4;
          }
        } else if (my_disc.upper_ & 0x20000UL) {
          my_disc.data_ |= 0x40810000000ULL;
          op_disc.data_ ^= 0x40810000000ULL;
          count += 3;
        }
      } else if (my_disc.upper_ & 0x400UL) {
        my_disc.data_ |= 0x810000000ULL;
        op_disc.data_ ^= 0x810000000ULL;
        count += 2;
      }
    } else if (my_disc.upper_ & 0x8UL) {
      my_disc.data_ |= 0x10000000ULL;
      op_disc.data_ ^= 0x10000000ULL;
      count += 1;
    }
  }
  if (op_disc.lower_ & 0x1000UL) {
    if (my_disc.lower_ & 0x8UL) {
      my_disc.data_ |= 0x1000ULL;
      op_disc.data_ ^= 0x1000ULL;
      count += 1;
    }
  }
  return count;
}

static int f_26(bit_matrix& my_disc, bit_matrix& op_disc) {
  int count = 0;
  if (op_disc.lower_ & 0x200000UL) {
    if (op_disc.lower_ & 0x100000UL) {
      if (op_disc.lower_ & 0x80000UL) {
        if (op_disc.lower_ & 0x40000UL) {
          if (op_disc.lower_ & 0x20000UL) {
            if (my_disc.lower_ & 0x10000UL) {
              my_disc.data_ |= 0x3e0000ULL;
              op_disc.data_ ^= 0x3e0000ULL;
              count += 5;
            }
          } else if (my_disc.lower_ & 0x20000UL) {
            my_disc.data_ |= 0x3c0000ULL;
            op_disc.data_ ^= 0x3c0000ULL;
            count += 4;
          }
        } else if (my_disc.lower_ & 0x40000UL) {
          my_disc.data_ |= 0x380000ULL;
          op_disc.data_ ^= 0x380000ULL;
          count += 3;
        }
      } else if (my_disc.lower_ & 0x80000UL) {
        my_disc.data_ |= 0x300000ULL;
        op_disc.data_ ^= 0x300000ULL;
        count += 2;
      }
    } else if (my_disc.lower_ & 0x100000UL) {
      my_disc.data_ |= 0x200000ULL;
      op_disc.data_ ^= 0x200000ULL;
      count += 1;
    }
  }
  if (op_disc.lower_ & 0x40000000UL) {
    if (op_disc.upper_ & 0x40UL) {
      if (op_disc.upper_ & 0x4000UL) {
        if (op_disc.upper_ & 0x400000UL) {
          if (my_disc.upper_ & 0x40000000UL) {
            my_disc.data_ |= 0x40404040000000ULL;
            op_disc.data_ ^= 0x40404040000000ULL;
            count += 4;
          }
        } else if (my_disc.upper_ & 0x400000UL) {
          my_disc.data_ |= 0x404040000000ULL;
          op_disc.data_ ^= 0x404040000000ULL;
          count += 3;
        }
      } else if (my_disc.upper_ & 0x4000UL) {
        my_disc.data_ |= 0x4040000000ULL;
        op_disc.data_ ^= 0x4040000000ULL;
        count += 2;
      }
    } else if (my_disc.upper_ & 0x40UL) {
      my_disc.data_ |= 0x40000000ULL;
      op_disc.data_ ^= 0x40000000ULL;
      count += 1;
    }
  }
  if (op_disc.lower_ & 0x4000UL) {
    if (my_disc.lower_ & 0x40UL) {
      my_disc.data_ |= 0x4000ULL;
      op_disc.data_ ^= 0x4000ULL;
      count += 1;
    }
  }
  if (op_disc.lower_ & 0x20000000UL) {
    if (op_disc.upper_ & 0x10UL) {
      if (op_disc.upper_ & 0x800UL) {
        if (op_disc.upper_ & 0x40000UL) {
          if (my_disc.upper_ & 0x2000000UL) {
            my_disc.data_ |= 0x4081020000000ULL;
            op_disc.data_ ^= 0x4081020000000ULL;
            count += 4;
          }
        } else if (my_disc.upper_ & 0x40000UL) {
          my_disc.data_ |= 0x81020000000ULL;
          op_disc.data_ ^= 0x81020000000ULL;
          count += 3;
        }
      } else if (my_disc.upper_ & 0x800UL) {
        my_disc.data_ |= 0x1020000000ULL;
        op_disc.data_ ^= 0x1020000000ULL;
        count += 2;
      }
    } else if (my_disc.upper_ & 0x10UL) {
      my_disc.data_ |= 0x20000000ULL;
      op_disc.data_ ^= 0x20000000ULL;
      count += 1;
    }
  }
  if (op_disc.lower_ & 0x2000UL) {
    if (my_disc.lower_ & 0x10UL) {
      my_disc.data_ |= 0x2000ULL;
      op_disc.data_ ^= 0x2000ULL;
      count += 1;
    }
  }
  return count;
}

static int f_27(bit_matrix& my_disc, bit_matrix& op_disc) {
  int count = 0;
  if (op_disc.lower_ & 0x400000UL) {
    if (op_disc.lower_ & 0x200000UL) {
      if (op_disc.lower_ & 0x100000UL) {
        if (op_disc.lower_ & 0x80000UL) {
          if (op_disc.lower_ & 0x40000UL) {
            if (op_disc.lower_ & 0x20000UL) {
              if (my_disc.lower_ & 0x10000UL) {
                my_disc.data_ |= 0x7e0000ULL;
                op_disc.data_ ^= 0x7e0000ULL;
                count += 6;
              }
            } else if (my_disc.lower_ & 0x20000UL) {
              my_disc.data_ |= 0x7c0000ULL;
              op_disc.data_ ^= 0x7c0000ULL;
              count += 5;
            }
          } else if (my_disc.lower_ & 0x40000UL) {
            my_disc.data_ |= 0x780000ULL;
            op_disc.data_ ^= 0x780000ULL;
            count += 4;
          }
        } else if (my_disc.lower_ & 0x80000UL) {
          my_disc.data_ |= 0x700000ULL;
          op_disc.data_ ^= 0x700000ULL;
          count += 3;
        }
      } else if (my_disc.lower_ & 0x100000UL) {
        my_disc.data_ |= 0x600000ULL;
        op_disc.data_ ^= 0x600000ULL;
        count += 2;
      }
    } else if (my_disc.lower_ & 0x200000UL) {
      my_disc.data_ |= 0x400000ULL;
      op_disc.data_ ^= 0x400000ULL;
      count += 1;
    }
  }
  if (op_disc.lower_ & 0x80000000UL) {
    if (op_disc.upper_ & 0x80UL) {
      if (op_disc.upper_ & 0x8000UL) {
        if (op_disc.upper_ & 0x800000UL) {
          if (my_disc.upper_ & 0x80000000UL) {
            my_disc.data_ |= 0x80808080000000ULL;
            op_disc.data_ ^= 0x80808080000000ULL;
            count += 4;
          }
        } else if (my_disc.upper_ & 0x800000UL) {
          my_disc.data_ |= 0x808080000000ULL;
          op_disc.data_ ^= 0x808080000000ULL;
          count += 3;
        }
      } else if (my_disc.upper_ & 0x8000UL) {
        my_disc.data_ |= 0x8080000000ULL;
        op_disc.data_ ^= 0x8080000000ULL;
        count += 2;
      }
    } else if (my_disc.upper_ & 0x80UL) {
      my_disc.data_ |= 0x80000000ULL;
      op_disc.data_ ^= 0x80000000ULL;
      count += 1;
    }
  }
  if (op_disc.lower_ & 0x8000UL) {
    if (my_disc.lower_ & 0x80UL) {
      my_disc.data_ |= 0x8000ULL;
      op_disc.data_ ^= 0x8000ULL;
      count += 1;
    }
  }
  if (op_disc.lower_ & 0x40000000UL) {
    if (op_disc.upper_ & 0x20UL) {
      if (op_disc.upper_ & 0x1000UL) {
        if (op_disc.upper_ & 0x80000UL) {
          if (my_disc.upper_ & 0x4000000UL) {
            my_disc.data_ |= 0x8102040000000ULL;
            op_disc.data_ ^= 0x8102040000000ULL;
            count += 4;
          }
        } else if (my_disc.upper_ & 0x80000UL) {
          my_disc.data_ |= 0x102040000000ULL;
          op_disc.data_ ^= 0x102040000000ULL;
          count += 3;
        }
      } else if (my_disc.upper_ & 0x1000UL) {
        my_disc.data_ |= 0x2040000000ULL;
        op_disc.data_ ^= 0x2040000000ULL;
        count += 2;
      }
    } else if (my_disc.upper_ & 0x20UL) {
      my_disc.data_ |= 0x40000000ULL;
      op_disc.data_ ^= 0x40000000ULL;
      count += 1;
    }
  }
  if (op_disc.lower_ & 0x4000UL) {
    if (my_disc.lower_ & 0x20UL) {
      my_disc.data_ |= 0x4000ULL;
      op_disc.data_ ^= 0x4000ULL;
      count += 1;
    }
  }
  return count;
}

static int f_30(bit_matrix& my_disc, bit_matrix& op_disc) {
  int count = 0;
  if (op_disc.lower_ & 0x2000000UL) {
    if (op_disc.lower_ & 0x4000000UL) {
      if (op_disc.lower_ & 0x8000000UL) {
        if (op_disc.lower_ & 0x10000000UL) {
          if (op_disc.lower_ & 0x20000000UL) {
            if (op_disc.lower_ & 0x40000000UL) {
              if (my_disc.lower_ & 0x80000000UL) {
                my_disc.data_ |= 0x7e000000ULL;
                op_disc.data_ ^= 0x7e000000ULL;
                count += 6;
              }
            } else if (my_disc.lower_ & 0x40000000UL) {
              my_disc.data_ |= 0x3e000000ULL;
              op_disc.data_ ^= 0x3e000000ULL;
              count += 5;
            }
          } else if (my_disc.lower_ & 0x20000000UL) {
            my_disc.data_ |= 0x1e000000ULL;
            op_disc.data_ ^= 0x1e000000ULL;
            count += 4;
          }
        } else if (my_disc.lower_ & 0x10000000UL) {
          my_disc.data_ |= 0xe000000ULL;
          op_disc.data_ ^= 0xe000000ULL;
          count += 3;
        }
      } else if (my_disc.lower_ & 0x8000000UL) {
        my_disc.data_ |= 0x6000000ULL;
        op_disc.data_ ^= 0x6000000ULL;
        count += 2;
      }
    } else if (my_disc.lower_ & 0x4000000UL) {
      my_disc.data_ |= 0x2000000ULL;
      op_disc.data_ ^= 0x2000000ULL;
      count += 1;
    }
  }
  if (op_disc.upper_ & 0x1UL) {
    if (op_disc.upper_ & 0x100UL) {
      if (op_disc.upper_ & 0x10000UL) {
        if (my_disc.upper_ & 0x1000000UL) {
          my_disc.data_ |= 0x1010100000000ULL;
          op_disc.data_ ^= 0x1010100000000ULL;
          count += 3;
        }
      } else if (my_disc.upper_ & 0x10000UL) {
        my_disc.data_ |= 0x10100000000ULL;
        op_disc.data_ ^= 0x10100000000ULL;
        count += 2;
      }
    } else if (my_disc.upper_ & 0x100UL) {
      my_disc.data_ |= 0x100000000ULL;
      op_disc.data_ ^= 0x100000000ULL;
      count += 1;
    }
  }
  if (op_disc.lower_ & 0x10000UL) {
    if (op_disc.lower_ & 0x100UL) {
      if (my_disc.lower_ & 0x1UL) {
        my_disc.data_ |= 0x10100ULL;
        op_disc.data_ ^= 0x10100ULL;
        count += 2;
      }
    } else if (my_disc.lower_ & 0x100UL) {
      my_disc.data_ |= 0x10000ULL;
      op_disc.data_ ^= 0x10000ULL;
      count += 1;
    }
  }
  if (op_disc.upper_ & 0x2UL) {
    if (op_disc.upper_ & 0x400UL) {
      if (op_disc.upper_ & 0x80000UL) {
        if (my_disc.upper_ & 0x10000000UL) {
          my_disc.data_ |= 0x8040200000000ULL;
          op_disc.data_ ^= 0x8040200000000ULL;
          count += 3;
        }
      } else if (my_disc.upper_ & 0x80000UL) {
        my_disc.data_ |= 0x40200000000ULL;
        op_disc.data_ ^= 0x40200000000ULL;
        count += 2;
      }
    } else if (my_disc.upper_ & 0x400UL) {
      my_disc.data_ |= 0x200000000ULL;
      op_disc.data_ ^= 0x200000000ULL;
      count += 1;
    }
  }
  if (op_disc.lower_ & 0x20000UL) {
    if (op_disc.lower_ & 0x400UL) {
      if (my_disc.lower_ & 0x8UL) {
        my_disc.data_ |= 0x20400ULL;
        op_disc.data_ ^= 0x20400ULL;
        count += 2;
      }
    } else if (my_disc.lower_ & 0x400UL) {
      my_disc.data_ |= 0x20000ULL;
      op_disc.data_ ^= 0x20000ULL;
      count += 1;
    }
  }
  return count;
}

static int f_31(bit_matrix& my_disc, bit_matrix& op_disc) {
  int count = 0;
  if (op_disc.lower_ & 0x4000000UL) {
    if (op_disc.lower_ & 0x8000000UL) {
      if (op_disc.lower_ & 0x10000000UL) {
        if (op_disc.lower_ & 0x20000000UL) {
          if (op_disc.lower_ & 0x40000000UL) {
            if (my_disc.lower_ & 0x80000000UL) {
              my_disc.data_ |= 0x7c000000ULL;
              op_disc.data_ ^= 0x7c000000ULL;
              count += 5;
            }
          } else if (my_disc.lower_ & 0x40000000UL) {
            my_disc.data_ |= 0x3c000000ULL;
            op_disc.data_ ^= 0x3c000000ULL;
            count += 4;
          }
        } else if (my_disc.lower_ & 0x20000000UL) {
          my_disc.data_ |= 0x1c000000ULL;
          op_disc.data_ ^= 0x1c000000ULL;
          count += 3;
        }
      } else if (my_disc.lower_ & 0x10000000UL) {
        my_disc.data_ |= 0xc000000ULL;
        op_disc.data_ ^= 0xc000000ULL;
        count += 2;
      }
    } else if (my_disc.lower_ & 0x8000000UL) {
      my_disc.data_ |= 0x4000000ULL;
      op_disc.data_ ^= 0x4000000ULL;
      count += 1;
    }
  }
  if (op_disc.upper_ & 0x2UL) {
    if (op_disc.upper_ & 0x200UL) {
      if (op_disc.upper_ & 0x20000UL) {
        if (my_disc.upper_ & 0x2000000UL) {
          my_disc.data_ |= 0x2020200000000ULL;
          op_disc.data_ ^= 0x2020200000000ULL;
          count += 3;
        }
      } else if (my_disc.upper_ & 0x20000UL) {
        my_disc.data_ |= 0x20200000000ULL;
        op_disc.data_ ^= 0x20200000000ULL;
        count += 2;
      }
    } else if (my_disc.upper_ & 0x200UL) {
      my_disc.data_ |= 0x200000000ULL;
      op_disc.data_ ^= 0x200000000ULL;
      count += 1;
    }
  }
  if (op_disc.lower_ & 0x20000UL) {
    if (op_disc.lower_ & 0x200UL) {
      if (my_disc.lower_ & 0x2UL) {
        my_disc.data_ |= 0x20200ULL;
        op_disc.data_ ^= 0x20200ULL;
        count += 2;
      }
    } else if (my_disc.lower_ & 0x200UL) {
      my_disc.data_ |= 0x20000ULL;
      op_disc.data_ ^= 0x20000ULL;
      count += 1;
    }
  }
  if (op_disc.upper_ & 0x4UL) {
    if (op_disc.upper_ & 0x800UL) {
      if (op_disc.upper_ & 0x100000UL) {
        if (my_disc.upper_ & 0x20000000UL) {
          my_disc.data_ |= 0x10080400000000ULL;
          op_disc.data_ ^= 0x10080400000000ULL;
          count += 3;
        }
      } else if (my_disc.upper_ & 0x100000UL) {
        my_disc.data_ |= 0x80400000000ULL;
        op_disc.data_ ^= 0x80400000000ULL;
        count += 2;
      }
    } else if (my_disc.upper_ & 0x800UL) {
      my_disc.data_ |= 0x400000000ULL;
      op_disc.data_ ^= 0x400000000ULL;
      count += 1;
    }
  }
  if (op_disc.lower_ & 0x40000UL) {
    if (op_disc.lower_ & 0x800UL) {
      if (my_disc.lower_ & 0x10UL) {
        my_disc.data_ |= 0x40800ULL;
        op_disc.data_ ^= 0x40800ULL;
        count += 2;
      }
    } else if (my_disc.lower_ & 0x800UL) {
      my_disc.data_ |= 0x40000ULL;
      op_disc.data_ ^= 0x40000ULL;
      count += 1;
    }
  }
  return count;
}

static int f_32(bit_matrix& my_disc, bit_matrix& op_disc) {
  int count = 0;
  if (op_disc.lower_ & 0x8000000UL) {
    if (op_disc.lower_ & 0x10000000UL) {
      if (op_disc.lower_ & 0x20000000UL) {
        if (op_disc.lower_ & 0x40000000UL) {
          if (my_disc.lower_ & 0x80000000UL) {
            my_disc.data_ |= 0x78000000ULL;
            op_disc.data_ ^= 0x78000000ULL;
            count += 4;
          }
        } else if (my_disc.lower_ & 0x40000000UL) {
          my_disc.data_ |= 0x38000000ULL;
          op_disc.data_ ^= 0x38000000ULL;
          count += 3;
        }
      } else if (my_disc.lower_ & 0x20000000UL) {
        my_disc.data_ |= 0x18000000ULL;
        op_disc.data_ ^= 0x18000000ULL;
        count += 2;
      }
    } else if (my_disc.lower_ & 0x10000000UL) {
      my_disc.data_ |= 0x8000000ULL;
      op_disc.data_ ^= 0x8000000ULL;
      count += 1;
    }
  }
  if (op_disc.lower_ & 0x2000000UL) {
    if (my_disc.lower_ & 0x1000000UL) {
      my_disc.data_ |= 0x2000000ULL;
      op_disc.data_ ^= 0x2000000ULL;
      count += 1;
    }
  }
  if (op_disc.upper_ & 0x4UL) {
    if (op_disc.upper_ & 0x400UL) {
      if (op_disc.upper_ & 0x40000UL) {
        if (my_disc.upper_ & 0x4000000UL) {
          my_disc.data_ |= 0x4040400000000ULL;
          op_disc.data_ ^= 0x4040400000000ULL;
          count += 3;
        }
      } else if (my_disc.upper_ & 0x40000UL) {
        my_disc.data_ |= 0x40400000000ULL;
        op_disc.data_ ^= 0x40400000000ULL;
        count += 2;
      }
    } else if (my_disc.upper_ & 0x400UL) {
      my_disc.data_ |= 0x400000000ULL;
      op_disc.data_ ^= 0x400000000ULL;
      count += 1;
    }
  }
  if (op_disc.lower_ & 0x40000UL) {
    if (op_disc.lower_ & 0x400UL) {
      if (my_disc.lower_ & 0x4UL) {
        my_disc.data_ |= 0x40400ULL;
        op_disc.data_ ^= 0x40400ULL;
        count += 2;
      }
    } else if (my_disc.lower_ & 0x400UL) {
      my_disc.data_ |= 0x40000ULL;
      op_disc.data_ ^= 0x40000ULL;
      count += 1;
    }
  }
  if (op_disc.upper_ & 0x8UL) {
    if (op_disc.upper_ & 0x1000UL) {
      if (op_disc.upper_ & 0x200000UL) {
        if (my_disc.upper_ & 0x40000000UL) {
          my_disc.data_ |= 0x20100800000000ULL;
          op_disc.data_ ^= 0x20100800000000ULL;
          count += 3;
        }
      } else if (my_disc.upper_ & 0x200000UL) {
        my_disc.data_ |= 0x100800000000ULL;
        op_disc.data_ ^= 0x100800000000ULL;
        count += 2;
      }
    } else if (my_disc.upper_ & 0x1000UL) {
      my_disc.data_ |= 0x800000000ULL;
      op_disc.data_ ^= 0x800000000ULL;
      count += 1;
    }
  }
  if (op_disc.lower_ & 0x80000UL) {
    if (op_disc.lower_ & 0x1000UL) {
      if (my_disc.lower_ & 0x20UL) {
        my_disc.data_ |= 0x81000ULL;
        op_disc.data_ ^= 0x81000ULL;
        count += 2;
      }
    } else if (my_disc.lower_ & 0x1000UL) {
      my_disc.data_ |= 0x80000ULL;
      op_disc.data_ ^= 0x80000ULL;
      count += 1;
    }
  }
  if (op_disc.upper_ & 0x2UL) {
    if (my_disc.upper_ & 0x100UL) {
      my_disc.data_ |= 0x200000000ULL;
      op_disc.data_ ^= 0x200000000ULL;
      count += 1;
    }
  }
  if (op_disc.lower_ & 0x20000UL) {
    if (my_disc.lower_ & 0x100UL) {
      my_disc.data_ |= 0x20000ULL;
      op_disc.data_ ^= 0x20000ULL;
      count += 1;
    }
  }
  return count;
}

static int f_33(bit_matrix& my_disc, bit_matrix& op_disc) {
  int count = 0;
  if (op_disc.lower_ & 0x10000000UL) {
    if (op_disc.lower_ & 0x20000000UL) {
      if (op_disc.lower_ & 0x40000000UL) {
        if (my_disc.lower_ & 0x80000000UL) {
          my_disc.data_ |= 0x70000000ULL;
          op_disc.data_ ^= 0x70000000ULL;
          count += 3;
        }
      } else if (my_disc.lower_ & 0x40000000UL) {
        my_disc.data_ |= 0x30000000ULL;
        op_disc.data_ ^= 0x30000000ULL;
        count += 2;
      }
    } else if (my_disc.lower_ & 0x20000000UL) {
      my_disc.data_ |= 0x10000000ULL;
      op_disc.data_ ^= 0x10000000ULL;
      count += 1;
    }
  }
  if (op_disc.lower_ & 0x4000000UL) {
    if (op_disc.lower_ & 0x2000000UL) {
      if (my_disc.lower_ & 0x1000000UL) {
        my_disc.data_ |= 0x6000000ULL;
        op_disc.data_ ^= 0x6000000ULL;
        count += 2;
      }
    } else if (my_disc.lower_ & 0x2000000UL) {
      my_disc.data_ |= 0x4000000ULL;
      op_disc.data_ ^= 0x4000000ULL;
      count += 1;
    }
  }
  if (op_disc.upper_ & 0x8UL) {
    if (op_disc.upper_ & 0x800UL) {
      if (op_disc.upper_ & 0x80000UL) {
        if (my_disc.upper_ & 0x8000000UL) {
          my_disc.data_ |= 0x8080800000000ULL;
          op_disc.data_ ^= 0x8080800000000ULL;
          count += 3;
        }
      } else if (my_disc.upper_ & 0x80000UL) {
        my_disc.data_ |= 0x80800000000ULL;
        op_disc.data_ ^= 0x80800000000ULL;
        count += 2;
      }
    } else if (my_disc.upper_ & 0x800UL) {
      my_disc.data_ |= 0x800000000ULL;
      op_disc.data_ ^= 0x800000000ULL;
      count += 1;
    }
  }
  if (op_disc.lower_ & 0x80000UL) {
    if (op_disc.lower_ & 0x800UL) {
      if (my_disc.lower_ & 0x8UL) {
        my_disc.data_ |= 0x80800ULL;
        op_disc.data_ ^= 0x80800ULL;
        count += 2;
      }
    } else if (my_disc.lower_ & 0x800UL) {
      my_disc.data_ |= 0x80000ULL;
      op_disc.data_ ^= 0x80000ULL;
      count += 1;
    }
  }
  if (op_disc.upper_ & 0x10UL) {
    if (op_disc.upper_ & 0x2000UL) {
      if (op_disc.upper_ & 0x400000UL) {
        if (my_disc.upper_ & 0x80000000UL) {
          my_disc.data_ |= 0x40201000000000ULL;
          op_disc.data_ ^= 0x40201000000000ULL;
          count += 3;
        }
      } else if (my_disc.upper_ & 0x400000UL) {
        my_disc.data_ |= 0x201000000000ULL;
        op_disc.data_ ^= 0x201000000000ULL;
        count += 2;
      }
    } else if (my_disc.upper_ & 0x2000UL) {
      my_disc.data_ |= 0x1000000000ULL;
      op_disc.data_ ^= 0x1000000000ULL;
      count += 1;
    }
  }
  if (op_disc.lower_ & 0x100000UL) {
    if (op_disc.lower_ & 0x2000UL) {
      if (my_disc.lower_ & 0x40UL) {
        my_disc.data_ |= 0x102000ULL;
        op_disc.data_ ^= 0x102000ULL;
        count += 2;
      }
    } else if (my_disc.lower_ & 0x2000UL) {
      my_disc.data_ |= 0x100000ULL;
      op_disc.data_ ^= 0x100000ULL;
      count += 1;
    }
  }
  if (op_disc.upper_ & 0x4UL) {
    if (op_disc.upper_ & 0x200UL) {
      if (my_disc.upper_ & 0x10000UL) {
        my_disc.data_ |= 0x20400000000ULL;
        op_disc.data_ ^= 0x20400000000ULL;
        count += 2;
      }
    } else if (my_disc.upper_ & 0x200UL) {
      my_disc.data_ |= 0x400000000ULL;
      op_disc.data_ ^= 0x400000000ULL;
      count += 1;
    }
  }
  if (op_disc.lower_ & 0x40000UL) {
    if (op_disc.lower_ & 0x200UL) {
      if (my_disc.lower_ & 0x1UL) {
        my_disc.data_ |= 0x40200ULL;
        op_disc.data_ ^= 0x40200ULL;
        count += 2;
      }
    } else if (my_disc.lower_ & 0x200UL) {
      my_disc.data_ |= 0x40000ULL;
      op_disc.data_ ^= 0x40000ULL;
      count += 1;
    }
  }
  return count;
}

static int f_34(bit_matrix& my_disc, bit_matrix& op_disc) {
  int count = 0;
  if (op_disc.lower_ & 0x20000000UL) {
    if (op_disc.lower_ & 0x40000000UL) {
      if (my_disc.lower_ & 0x80000000UL) {
        my_disc.data_ |= 0x60000000ULL;
        op_disc.data_ ^= 0x60000000ULL;
        count += 2;
      }
    } else if (my_disc.lower_ & 0x40000000UL) {
      my_disc.data_ |= 0x20000000ULL;
      op_disc.data_ ^= 0x20000000ULL;
      count += 1;
    }
  }
  if (op_disc.lower_ & 0x8000000UL) {
    if (op_disc.lower_ & 0x4000000UL) {
      if (op_disc.lower_ & 0x2000000UL) {
        if (my_disc.lower_ & 0x1000000UL) {
          my_disc.data_ |= 0xe000000ULL;
          op_disc.data_ ^= 0xe000000ULL;
          count += 3;
        }
      } else if (my_disc.lower_ & 0x2000000UL) {
        my_disc.data_ |= 0xc000000ULL;
        op_disc.data_ ^= 0xc000000ULL;
        count += 2;
      }
    } else if (my_disc.lower_ & 0x4000000UL) {
      my_disc.data_ |= 0x8000000ULL;
      op_disc.data_ ^= 0x8000000ULL;
      count += 1;
    }
  }
  if (op_disc.upper_ & 0x10UL) {
    if (op_disc.upper_ & 0x1000UL) {
      if (op_disc.upper_ & 0x100000UL) {
        if (my_disc.upper_ & 0x10000000UL) {
          my_disc.data_ |= 0x10101000000000ULL;
          op_disc.data_ ^= 0x10101000000000ULL;
          count += 3;
        }
      } else if (my_disc.upper_ & 0x100000UL) {
        my_disc.data_ |= 0x101000000000ULL;
        op_disc.data_ ^= 0x101000000000ULL;
        count += 2;
      }
    } else if (my_disc.upper_ & 0x1000UL) {
      my_disc.data_ |= 0x1000000000ULL;
      op_disc.data_ ^= 0x1000000000ULL;
      count += 1;
    }
  }
  if (op_disc.lower_ & 0x100000UL) {
    if (op_disc.lower_ & 0x1000UL) {
      if (my_disc.lower_ & 0x10UL) {
        my_disc.data_ |= 0x101000ULL;
        op_disc.data_ ^= 0x101000ULL;
        count += 2;
      }
    } else if (my_disc.lower_ & 0x1000UL) {
      my_disc.data_ |= 0x100000ULL;
      op_disc.data_ ^= 0x100000ULL;
      count += 1;
    }
  }
  if (op_disc.upper_ & 0x20UL) {
    if (op_disc.upper_ & 0x4000UL) {
      if (my_disc.upper_ & 0x800000UL) {
        my_disc.data_ |= 0x402000000000ULL;
        op_disc.data_ ^= 0x402000000000ULL;
        count += 2;
      }
    } else if (my_disc.upper_ & 0x4000UL) {
      my_disc.data_ |= 0x2000000000ULL;
      op_disc.data_ ^= 0x2000000000ULL;
      count += 1;
    }
  }
  if (op_disc.lower_ & 0x200000UL) {
    if (op_disc.lower_ & 0x4000UL) {
      if (my_disc.lower_ & 0x80UL) {
        my_disc.data_ |= 0x204000ULL;
        op_disc.data_ ^= 0x204000ULL;
        count += 2;
      }
    } else if (my_disc.lower_ & 0x4000UL) {
      my_disc.data_ |= 0x200000ULL;
      op_disc.data_ ^= 0x200000ULL;
      count += 1;
    }
  }
  if (op_disc.upper_ & 0x8UL) {
    if (op_disc.upper_ & 0x400UL) {
      if (op_disc.upper_ & 0x20000UL) {
        if (my_disc.upper_ & 0x1000000UL) {
          my_disc.data_ |= 0x2040800000000ULL;
          op_disc.data_ ^= 0x2040800000000ULL;
          count += 3;
        }
      } else if (my_disc.upper_ & 0x20000UL) {
        my_disc.data_ |= 0x40800000000ULL;
        op_disc.data_ ^= 0x40800000000ULL;
        count += 2;
      }
    } else if (my_disc.upper_ & 0x400UL) {
      my_disc.data_ |= 0x800000000ULL;
      op_disc.data_ ^= 0x800000000ULL;
      count += 1;
    }
  }
  if (op_disc.lower_ & 0x80000UL) {
    if (op_disc.lower_ & 0x400UL) {
      if (my_disc.lower_ & 0x2UL) {
        my_disc.data_ |= 0x80400ULL;
        op_disc.data_ ^= 0x80400ULL;
        count += 2;
      }
    } else if (my_disc.lower_ & 0x400UL) {
      my_disc.data_ |= 0x80000ULL;
      op_disc.data_ ^= 0x80000ULL;
      count += 1;
    }
  }
  return count;
}

static int f_35(bit_matrix& my_disc, bit_matrix& op_disc) {
  int count = 0;
  if (op_disc.lower_ & 0x40000000UL) {
    if (my_disc.lower_ & 0x80000000UL) {
      my_disc.data_ |= 0x40000000ULL;
      op_disc.data_ ^= 0x40000000ULL;
      count += 1;
    }
  }
  if (op_disc.lower_ & 0x10000000UL) {
    if (op_disc.lower_ & 0x8000000UL) {
      if (op_disc.lower_ & 0x4000000UL) {
        if (op_disc.lower_ & 0x2000000UL) {
          if (my_disc.lower_ & 0x1000000UL) {
            my_disc.data_ |= 0x1e000000ULL;
            op_disc.data_ ^= 0x1e000000ULL;
            count += 4;
          }
        } else if (my_disc.lower_ & 0x2000000UL) {
          my_disc.data_ |= 0x1c000000ULL;
          op_disc.data_ ^= 0x1c000000ULL;
          count += 3;
        }
      } else if (my_disc.lower_ & 0x4000000UL) {
        my_disc.data_ |= 0x18000000ULL;
        op_disc.data_ ^= 0x18000000ULL;
        count += 2;
      }
    } else if (my_disc.lower_ & 0x8000000UL) {
      my_disc.data_ |= 0x10000000ULL;
      op_disc.data_ ^= 0x10000000ULL;
      count += 1;
    }
  }
  if (op_disc.upper_ & 0x20UL) {
    if (op_disc.upper_ & 0x2000UL) {
      if (op_disc.upper_ & 0x200000UL) {
        if (my_disc.upper_ & 0x20000000UL) {
          my_disc.data_ |= 0x20202000000000ULL;
          op_disc.data_ ^= 0x20202000000000ULL;
          count += 3;
        }
      } else if (my_disc.upper_ & 0x200000UL) {
        my_disc.data_ |= 0x202000000000ULL;
        op_disc.data_ ^= 0x202000000000ULL;
        count += 2;
      }
    } else if (my_disc.upper_ & 0x2000UL) {
      my_disc.data_ |= 0x2000000000ULL;
      op_disc.data_ ^= 0x2000000000ULL;
      count += 1;
    }
  }
  if (op_disc.lower_ & 0x200000UL) {
    if (op_disc.lower_ & 0x2000UL) {
      if (my_disc.lower_ & 0x20UL) {
        my_disc.data_ |= 0x202000ULL;
        op_disc.data_ ^= 0x202000ULL;
        count += 2;
      }
    } else if (my_disc.lower_ & 0x2000UL) {
      my_disc.data_ |= 0x200000ULL;
      op_disc.data_ ^= 0x200000ULL;
      count += 1;
    }
  }
  if (op_disc.upper_ & 0x40UL) {
    if (my_disc.upper_ & 0x8000UL) {
      my_disc.data_ |= 0x4000000000ULL;
      op_disc.data_ ^= 0x4000000000ULL;
      count += 1;
    }
  }
  if (op_disc.lower_ & 0x400000UL) {
    if (my_disc.lower_ & 0x8000UL) {
      my_disc.data_ |= 0x400000ULL;
      op_disc.data_ ^= 0x400000ULL;
      count += 1;
    }
  }
  if (op_disc.upper_ & 0x10UL) {
    if (op_disc.upper_ & 0x800UL) {
      if (op_disc.upper_ & 0x40000UL) {
        if (my_disc.upper_ & 0x2000000UL) {
          my_disc.data_ |= 0x4081000000000ULL;
          op_disc.data_ ^= 0x4081000000000ULL;
          count += 3;
        }
      } else if (my_disc.upper_ & 0x40000UL) {
        my_disc.data_ |= 0x81000000000ULL;
        op_disc.data_ ^= 0x81000000000ULL;
        count += 2;
      }
    } else if (my_disc.upper_ & 0x800UL) {
      my_disc.data_ |= 0x1000000000ULL;
      op_disc.data_ ^= 0x1000000000ULL;
      count += 1;
    }
  }
  if (op_disc.lower_ & 0x100000UL) {
    if (op_disc.lower_ & 0x800UL) {
      if (my_disc.lower_ & 0x4UL) {
        my_disc.data_ |= 0x100800ULL;
        op_disc.data_ ^= 0x100800ULL;
        count += 2;
      }
    } else if (my_disc.lower_ & 0x800UL) {
      my_disc.data_ |= 0x100000ULL;
      op_disc.data_ ^= 0x100000ULL;
      count += 1;
    }
  }
  return count;
}

static int f_36(bit_matrix& my_disc, bit_matrix& op_disc) {
  int count = 0;
  if (op_disc.lower_ & 0x20000000UL) {
    if (op_disc.lower_ & 0x10000000UL) {
      if (op_disc.lower_ & 0x8000000UL) {
        if (op_disc.lower_ & 0x4000000UL) {
          if (op_disc.lower_ & 0x2000000UL) {
            if (my_disc.lower_ & 0x1000000UL) {
              my_disc.data_ |= 0x3e000000ULL;
              op_disc.data_ ^= 0x3e000000ULL;
              count += 5;
            }
          } else if (my_disc.lower_ & 0x2000000UL) {
            my_disc.data_ |= 0x3c000000ULL;
            op_disc.data_ ^= 0x3c000000ULL;
            count += 4;
          }
        } else if (my_disc.lower_ & 0x4000000UL) {
          my_disc.data_ |= 0x38000000ULL;
          op_disc.data_ ^= 0x38000000ULL;
          count += 3;
        }
      } else if (my_disc.lower_ & 0x8000000UL) {
        my_disc.data_ |= 0x30000000ULL;
        op_disc.data_ ^= 0x30000000ULL;
        count += 2;
      }
    } else if (my_disc.lower_ & 0x10000000UL) {
      my_disc.data_ |= 0x20000000ULL;
      op_disc.data_ ^= 0x20000000ULL;
      count += 1;
    }
  }
  if (op_disc.upper_ & 0x40UL) {
    if (op_disc.upper_ & 0x4000UL) {
      if (op_disc.upper_ & 0x400000UL) {
        if (my_disc.upper_ & 0x40000000UL) {
          my_disc.data_ |= 0x40404000000000ULL;
          op_disc.data_ ^= 0x40404000000000ULL;
          count += 3;
        }
      } else if (my_disc.upper_ & 0x400000UL) {
        my_disc.data_ |= 0x404000000000ULL;
        op_disc.data_ ^= 0x404000000000ULL;
        count += 2;
      }
    } else if (my_disc.upper_ & 0x4000UL) {
      my_disc.data_ |= 0x4000000000ULL;
      op_disc.data_ ^= 0x4000000000ULL;
      count += 1;
    }
  }
  if (op_disc.lower_ & 0x400000UL) {
    if (op_disc.lower_ & 0x4000UL) {
      if (my_disc.lower_ & 0x40UL) {
        my_disc.data_ |= 0x404000ULL;
        op_disc.data_ ^= 0x404000ULL;
        count += 2;
      }
    } else if (my_disc.lower_ & 0x4000UL) {
      my_disc.data_ |= 0x400000ULL;
      op_disc.data_ ^= 0x400000ULL;
      count += 1;
    }
  }
  if (op_disc.upper_ & 0x20UL) {
    if (op_disc.upper_ & 0x1000UL) {
      if (op_disc.upper_ & 0x80000UL) {
        if (my_disc.upper_ & 0x4000000UL) {
          my_disc.data_ |= 0x8102000000000ULL;
          op_disc.data_ ^= 0x8102000000000ULL;
          count += 3;
        }
      } else if (my_disc.upper_ & 0x80000UL) {
        my_disc.data_ |= 0x102000000000ULL;
        op_disc.data_ ^= 0x102000000000ULL;
        count += 2;
      }
    } else if (my_disc.upper_ & 0x1000UL) {
      my_disc.data_ |= 0x2000000000ULL;
      op_disc.data_ ^= 0x2000000000ULL;
      count += 1;
    }
  }
  if (op_disc.lower_ & 0x200000UL) {
    if (op_disc.lower_ & 0x1000UL) {
      if (my_disc.lower_ & 0x8UL) {
        my_disc.data_ |= 0x201000ULL;
        op_disc.data_ ^= 0x201000ULL;
        count += 2;
      }
    } else if (my_disc.lower_ & 0x1000UL) {
      my_disc.data_ |= 0x200000ULL;
      op_disc.data_ ^= 0x200000ULL;
      count += 1;
    }
  }
  return count;
}

static int f_37(bit_matrix& my_disc, bit_matrix& op_disc) {
  int count = 0;
  if (op_disc.lower_ & 0x40000000UL) {
    if (op_disc.lower_ & 0x20000000UL) {
      if (op_disc.lower_ & 0x10000000UL) {
        if (op_disc.lower_ & 0x8000000UL) {
          if (op_disc.lower_ & 0x4000000UL) {
            if (op_disc.lower_ & 0x2000000UL) {
              if (my_disc.lower_ & 0x1000000UL) {
                my_disc.data_ |= 0x7e000000ULL;
                op_disc.data_ ^= 0x7e000000ULL;
                count += 6;
              }
            } else if (my_disc.lower_ & 0x2000000UL) {
              my_disc.data_ |= 0x7c000000ULL;
              op_disc.data_ ^= 0x7c000000ULL;
              count += 5;
            }
          } else if (my_disc.lower_ & 0x4000000UL) {
            my_disc.data_ |= 0x78000000ULL;
            op_disc.data_ ^= 0x78000000ULL;
            count += 4;
          }
        } else if (my_disc.lower_ & 0x8000000UL) {
          my_disc.data_ |= 0x70000000ULL;
          op_disc.data_ ^= 0x70000000ULL;
          count += 3;
        }
      } else if (my_disc.lower_ & 0x10000000UL) {
        my_disc.data_ |= 0x60000000ULL;
        op_disc.data_ ^= 0x60000000ULL;
        count += 2;
      }
    } else if (my_disc.lower_ & 0x20000000UL) {
      my_disc.data_ |= 0x40000000ULL;
      op_disc.data_ ^= 0x40000000ULL;
      count += 1;
    }
  }
  if (op_disc.upper_ & 0x80UL) {
    if (op_disc.upper_ & 0x8000UL) {
      if (op_disc.upper_ & 0x800000UL) {
        if (my_disc.upper_ & 0x80000000UL) {
          my_disc.data_ |= 0x80808000000000ULL;
          op_disc.data_ ^= 0x80808000000000ULL;
          count += 3;
        }
      } else if (my_disc.upper_ & 0x800000UL) {
        my_disc.data_ |= 0x808000000000ULL;
        op_disc.data_ ^= 0x808000000000ULL;
        count += 2;
      }
    } else if (my_disc.upper_ & 0x8000UL) {
      my_disc.data_ |= 0x8000000000ULL;
      op_disc.data_ ^= 0x8000000000ULL;
      count += 1;
    }
  }
  if (op_disc.lower_ & 0x800000UL) {
    if (op_disc.lower_ & 0x8000UL) {
      if (my_disc.lower_ & 0x80UL) {
        my_disc.data_ |= 0x808000ULL;
        op_disc.data_ ^= 0x808000ULL;
        count += 2;
      }
    } else if (my_disc.lower_ & 0x8000UL) {
      my_disc.data_ |= 0x800000ULL;
      op_disc.data_ ^= 0x800000ULL;
      count += 1;
    }
  }
  if (op_disc.upper_ & 0x40UL) {
    if (op_disc.upper_ & 0x2000UL) {
      if (op_disc.upper_ & 0x100000UL) {
        if (my_disc.upper_ & 0x8000000UL) {
          my_disc.data_ |= 0x10204000000000ULL;
          op_disc.data_ ^= 0x10204000000000ULL;
          count += 3;
        }
      } else if (my_disc.upper_ & 0x100000UL) {
        my_disc.data_ |= 0x204000000000ULL;
        op_disc.data_ ^= 0x204000000000ULL;
        count += 2;
      }
    } else if (my_disc.upper_ & 0x2000UL) {
      my_disc.data_ |= 0x4000000000ULL;
      op_disc.data_ ^= 0x4000000000ULL;
      count += 1;
    }
  }
  if (op_disc.lower_ & 0x400000UL) {
    if (op_disc.lower_ & 0x2000UL) {
      if (my_disc.lower_ & 0x10UL) {
        my_disc.data_ |= 0x402000ULL;
        op_disc.data_ ^= 0x402000ULL;
        count += 2;
      }
    } else if (my_disc.lower_ & 0x2000UL) {
      my_disc.data_ |= 0x400000ULL;
      op_disc.data_ ^= 0x400000ULL;
      count += 1;
    }
  }
  return count;
}

static int f_40(bit_matrix& my_disc, bit_matrix& op_disc) {
  int count = 0;
  if (op_disc.upper_ & 0x2UL) {
    if (op_disc.upper_ & 0x4UL) {
      if (op_disc.upper_ & 0x8UL) {
        if (op_disc.upper_ & 0x10UL) {
          if (op_disc.upper_ & 0x20UL) {
            if (op_disc.upper_ & 0x40UL) {
              if (my_disc.upper_ & 0x80UL) {
                my_disc.data_ |= 0x7e00000000ULL;
                op_disc.data_ ^= 0x7e00000000ULL;
                count += 6;
              }
            } else if (my_disc.upper_ & 0x40UL) {
              my_disc.data_ |= 0x3e00000000ULL;
              op_disc.data_ ^= 0x3e00000000ULL;
              count += 5;
            }
          } else if (my_disc.upper_ & 0x20UL) {
            my_disc.data_ |= 0x1e00000000ULL;
            op_disc.data_ ^= 0x1e00000000ULL;
            count += 4;
          }
        } else if (my_disc.upper_ & 0x10UL) {
          my_disc.data_ |= 0xe00000000ULL;
          op_disc.data_ ^= 0xe00000000ULL;
          count += 3;
        }
      } else if (my_disc.upper_ & 0x8UL) {
        my_disc.data_ |= 0x600000000ULL;
        op_disc.data_ ^= 0x600000000ULL;
        count += 2;
      }
    } else if (my_disc.upper_ & 0x4UL) {
      my_disc.data_ |= 0x200000000ULL;
      op_disc.data_ ^= 0x200000000ULL;
      count += 1;
    }
  }
  if (op_disc.upper_ & 0x100UL) {
    if (op_disc.upper_ & 0x10000UL) {
      if (my_disc.upper_ & 0x1000000UL) {
        my_disc.data_ |= 0x1010000000000ULL;
        op_disc.data_ ^= 0x1010000000000ULL;
        count += 2;
      }
    } else if (my_disc.upper_ & 0x10000UL) {
      my_disc.data_ |= 0x10000000000ULL;
      op_disc.data_ ^= 0x10000000000ULL;
      count += 1;
    }
  }
  if (op_disc.lower_ & 0x1000000UL) {
    if (op_disc.lower_ & 0x10000UL) {
      if (op_disc.lower_ & 0x100UL) {
        if (my_disc.lower_ & 0x1UL) {
          my_disc.data_ |= 0x1010100ULL;
          op_disc.data_ ^= 0x1010100ULL;
          count += 3;
        }
      } else if (my_disc.lower_ & 0x100UL) {
        my_disc.data_ |= 0x1010000ULL;
        op_disc.data_ ^= 0x1010000ULL;
        count += 2;
      }
    } else if (my_disc.lower_ & 0x10000UL) {
      my_disc.data_ |= 0x1000000ULL;
      op_disc.data_ ^= 0x1000000ULL;
      count += 1;
    }
  }
  if (op_disc.upper_ & 0x200UL) {
    if (op_disc.upper_ & 0x40000UL) {
      if (my_disc.upper_ & 0x8000000UL) {
        my_disc.data_ |= 0x4020000000000ULL;
        op_disc.data_ ^= 0x4020000000000ULL;
        count += 2;
      }
    } else if (my_disc.upper_ & 0x40000UL) {
      my_disc.data_ |= 0x20000000000ULL;
      op_disc.data_ ^= 0x20000000000ULL;
      count += 1;
    }
  }
  if (op_disc.lower_ & 0x2000000UL) {
    if (op_disc.lower_ & 0x40000UL) {
      if (op_disc.lower_ & 0x800UL) {
        if (my_disc.lower_ & 0x10UL) {
          my_disc.data_ |= 0x2040800ULL;
          op_disc.data_ ^= 0x2040800ULL;
          count += 3;
        }
      } else if (my_disc.lower_ & 0x800UL) {
        my_disc.data_ |= 0x2040000ULL;
        op_disc.data_ ^= 0x2040000ULL;
        count += 2;
      }
    } else if (my_disc.lower_ & 0x40000UL) {
      my_disc.data_ |= 0x2000000ULL;
      op_disc.data_ ^= 0x2000000ULL;
      count += 1;
    }
  }
  return count;
}

static int f_41(bit_matrix& my_disc, bit_matrix& op_disc) {
  int count = 0;
  if (op_disc.upper_ & 0x4UL) {
    if (op_disc.upper_ & 0x8UL) {
      if (op_disc.upper_ & 0x10UL) {
        if (op_disc.upper_ & 0x20UL) {
          if (op_disc.upper_ & 0x40UL) {
            if (my_disc.upper_ & 0x80UL) {
              my_disc.data_ |= 0x7c00000000ULL;
              op_disc.data_ ^= 0x7c00000000ULL;
              count += 5;
            }
          } else if (my_disc.upper_ & 0x40UL) {
            my_disc.data_ |= 0x3c00000000ULL;
            op_disc.data_ ^= 0x3c00000000ULL;
            count += 4;
          }
        } else if (my_disc.upper_ & 0x20UL) {
          my_disc.data_ |= 0x1c00000000ULL;
          op_disc.data_ ^= 0x1c00000000ULL;
          count += 3;
        }
      } else if (my_disc.upper_ & 0x10UL) {
        my_disc.data_ |= 0xc00000000ULL;
        op_disc.data_ ^= 0xc00000000ULL;
        count += 2;
      }
    } else if (my_disc.upper_ & 0x8UL) {
      my_disc.data_ |= 0x400000000ULL;
      op_disc.data_ ^= 0x400000000ULL;
      count += 1;
    }
  }
  if (op_disc.upper_ & 0x200UL) {
    if (op_disc.upper_ & 0x20000UL) {
      if (my_disc.upper_ & 0x2000000UL) {
        my_disc.data_ |= 0x2020000000000ULL;
        op_disc.data_ ^= 0x2020000000000ULL;
        count += 2;
      }
    } else if (my_disc.upper_ & 0x20000UL) {
      my_disc.data_ |= 0x20000000000ULL;
      op_disc.data_ ^= 0x20000000000ULL;
      count += 1;
    }
  }
  if (op_disc.lower_ & 0x2000000UL) {
    if (op_disc.lower_ & 0x20000UL) {
      if (op_disc.lower_ & 0x200UL) {
        if (my_disc.lower_ & 0x2UL) {
          my_disc.data_ |= 0x2020200ULL;
          op_disc.data_ ^= 0x2020200ULL;
          count += 3;
        }
      } else if (my_disc.lower_ & 0x200UL) {
        my_disc.data_ |= 0x2020000ULL;
        op_disc.data_ ^= 0x2020000ULL;
        count += 2;
      }
    } else if (my_disc.lower_ & 0x20000UL) {
      my_disc.data_ |= 0x2000000ULL;
      op_disc.data_ ^= 0x2000000ULL;
      count += 1;
    }
  }
  if (op_disc.upper_ & 0x400UL) {
    if (op_disc.upper_ & 0x80000UL) {
      if (my_disc.upper_ & 0x10000000UL) {
        my_disc.data_ |= 0x8040000000000ULL;
        op_disc.data_ ^= 0x8040000000000ULL;
        count += 2;
      }
    } else if (my_disc.upper_ & 0x80000UL) {
      my_disc.data_ |= 0x40000000000ULL;
      op_disc.data_ ^= 0x40000000000ULL;
      count += 1;
    }
  }
  if (op_disc.lower_ & 0x4000000UL) {
    if (op_disc.lower_ & 0x80000UL) {
      if (op_disc.lower_ & 0x1000UL) {
        if (my_disc.lower_ & 0x20UL) {
          my_disc.data_ |= 0x4081000ULL;
          op_disc.data_ ^= 0x4081000ULL;
          count += 3;
        }
      } else if (my_disc.lower_ & 0x1000UL) {
        my_disc.data_ |= 0x4080000ULL;
        op_disc.data_ ^= 0x4080000ULL;
        count += 2;
      }
    } else if (my_disc.lower_ & 0x80000UL) {
      my_disc.data_ |= 0x4000000ULL;
      op_disc.data_ ^= 0x4000000ULL;
      count += 1;
    }
  }
  return count;
}

static int f_42(bit_matrix& my_disc, bit_matrix& op_disc) {
  int count = 0;
  if (op_disc.upper_ & 0x8UL) {
    if (op_disc.upper_ & 0x10UL) {
      if (op_disc.upper_ & 0x20UL) {
        if (op_disc.upper_ & 0x40UL) {
          if (my_disc.upper_ & 0x80UL) {
            my_disc.data_ |= 0x7800000000ULL;
            op_disc.data_ ^= 0x7800000000ULL;
            count += 4;
          }
        } else if (my_disc.upper_ & 0x40UL) {
          my_disc.data_ |= 0x3800000000ULL;
          op_disc.data_ ^= 0x3800000000ULL;
          count += 3;
        }
      } else if (my_disc.upper_ & 0x20UL) {
        my_disc.data_ |= 0x1800000000ULL;
        op_disc.data_ ^= 0x1800000000ULL;
        count += 2;
      }
    } else if (my_disc.upper_ & 0x10UL) {
      my_disc.data_ |= 0x800000000ULL;
      op_disc.data_ ^= 0x800000000ULL;
      count += 1;
    }
  }
  if (op_disc.upper_ & 0x2UL) {
    if (my_disc.upper_ & 0x1UL) {
      my_disc.data_ |= 0x200000000ULL;
      op_disc.data_ ^= 0x200000000ULL;
      count += 1;
    }
  }
  if (op_disc.upper_ & 0x400UL) {
    if (op_disc.upper_ & 0x40000UL) {
      if (my_disc.upper_ & 0x4000000UL) {
        my_disc.data_ |= 0x4040000000000ULL;
        op_disc.data_ ^= 0x4040000000000ULL;
        count += 2;
      }
    } else if (my_disc.upper_ & 0x40000UL) {
      my_disc.data_ |= 0x40000000000ULL;
      op_disc.data_ ^= 0x40000000000ULL;
      count += 1;
    }
  }
  if (op_disc.lower_ & 0x4000000UL) {
    if (op_disc.lower_ & 0x40000UL) {
      if (op_disc.lower_ & 0x400UL) {
        if (my_disc.lower_ & 0x4UL) {
          my_disc.data_ |= 0x4040400ULL;
          op_disc.data_ ^= 0x4040400ULL;
          count += 3;
        }
      } else if (my_disc.lower_ & 0x400UL) {
        my_disc.data_ |= 0x4040000ULL;
        op_disc.data_ ^= 0x4040000ULL;
        count += 2;
      }
    } else if (my_disc.lower_ & 0x40000UL) {
      my_disc.data_ |= 0x4000000ULL;
      op_disc.data_ ^= 0x4000000ULL;
      count += 1;
    }
  }
  if (op_disc.upper_ & 0x800UL) {
    if (op_disc.upper_ & 0x100000UL) {
      if (my_disc.upper_ & 0x20000000UL) {
        my_disc.data_ |= 0x10080000000000ULL;
        op_disc.data_ ^= 0x10080000000000ULL;
        count += 2;
      }
    } else if (my_disc.upper_ & 0x100000UL) {
      my_disc.data_ |= 0x80000000000ULL;
      op_disc.data_ ^= 0x80000000000ULL;
      count += 1;
    }
  }
  if (op_disc.lower_ & 0x8000000UL) {
    if (op_disc.lower_ & 0x100000UL) {
      if (op_disc.lower_ & 0x2000UL) {
        if (my_disc.lower_ & 0x40UL) {
          my_disc.data_ |= 0x8102000ULL;
          op_disc.data_ ^= 0x8102000ULL;
          count += 3;
        }
      } else if (my_disc.lower_ & 0x2000UL) {
        my_disc.data_ |= 0x8100000ULL;
        op_disc.data_ ^= 0x8100000ULL;
        count += 2;
      }
    } else if (my_disc.lower_ & 0x100000UL) {
      my_disc.data_ |= 0x8000000ULL;
      op_disc.data_ ^= 0x8000000ULL;
      count += 1;
    }
  }
  if (op_disc.upper_ & 0x200UL) {
    if (my_disc.upper_ & 0x10000UL) {
      my_disc.data_ |= 0x20000000000ULL;
      op_disc.data_ ^= 0x20000000000ULL;
      count += 1;
    }
  }
  if (op_disc.lower_ & 0x2000000UL) {
    if (my_disc.lower_ & 0x10000UL) {
      my_disc.data_ |= 0x2000000ULL;
      op_disc.data_ ^= 0x2000000ULL;
      count += 1;
    }
  }
  return count;
}

static int f_43(bit_matrix& my_disc, bit_matrix& op_disc) {
  int count = 0;
  if (op_disc.upper_ & 0x10UL) {
    if (op_disc.upper_ & 0x20UL) {
      if (op_disc.upper_ & 0x40UL) {
        if (my_disc.upper_ & 0x80UL) {
          my_disc.data_ |= 0x7000000000ULL;
          op_disc.data_ ^= 0x7000000000ULL;
          count += 3;
        }
      } else if (my_disc.upper_ & 0x40UL) {
        my_disc.data_ |= 0x3000000000ULL;
        op_disc.data_ ^= 0x3000000000ULL;
        count += 2;
      }
    } else if (my_disc.upper_ & 0x20UL) {
      my_disc.data_ |= 0x1000000000ULL;
      op_disc.data_ ^= 0x1000000000ULL;
      count += 1;
    }
  }
  if (op_disc.upper_ & 0x4UL) {
    if (op_disc.upper_ & 0x2UL) {
      if (my_disc.upper_ & 0x1UL) {
        my_disc.data_ |= 0x600000000ULL;
        op_disc.data_ ^= 0x600000000ULL;
        count += 2;
      }
    } else if (my_disc.upper_ & 0x2UL) {
      my_disc.data_ |= 0x400000000ULL;
      op_disc.data_ ^= 0x400000000ULL;
      count += 1;
    }
  }
  if (op_disc.upper_ & 0x800UL) {
    if (op_disc.upper_ & 0x80000UL) {
      if (my_disc.upper_ & 0x8000000UL) {
        my_disc.data_ |= 0x8080000000000ULL;
        op_disc.data_ ^= 0x8080000000000ULL;
        count += 2;
      }
    } else if (my_disc.upper_ & 0x80000UL) {
      my_disc.data_ |= 0x80000000000ULL;
      op_disc.data_ ^= 0x80000000000ULL;
      count += 1;
    }
  }
  if (op_disc.lower_ & 0x8000000UL) {
    if (op_disc.lower_ & 0x80000UL) {
      if (op_disc.lower_ & 0x800UL) {
        if (my_disc.lower_ & 0x8UL) {
          my_disc.data_ |= 0x8080800ULL;
          op_disc.data_ ^= 0x8080800ULL;
          count += 3;
        }
      } else if (my_disc.lower_ & 0x800UL) {
        my_disc.data_ |= 0x8080000ULL;
        op_disc.data_ ^= 0x8080000ULL;
        count += 2;
      }
    } else if (my_disc.lower_ & 0x80000UL) {
      my_disc.data_ |= 0x8000000ULL;
      op_disc.data_ ^= 0x8000000ULL;
      count += 1;
    }
  }
  if (op_disc.upper_ & 0x1000UL) {
    if (op_disc.upper_ & 0x200000UL) {
      if (my_disc.upper_ & 0x40000000UL) {
        my_disc.data_ |= 0x20100000000000ULL;
        op_disc.data_ ^= 0x20100000000000ULL;
        count += 2;
      }
    } else if (my_disc.upper_ & 0x200000UL) {
      my_disc.data_ |= 0x100000000000ULL;
      op_disc.data_ ^= 0x100000000000ULL;
      count += 1;
    }
  }
  if (op_disc.lower_ & 0x10000000UL) {
    if (op_disc.lower_ & 0x200000UL) {
      if (op_disc.lower_ & 0x4000UL) {
        if (my_disc.lower_ & 0x80UL) {
          my_disc.data_ |= 0x10204000ULL;
          op_disc.data_ ^= 0x10204000ULL;
          count += 3;
        }
      } else if (my_disc.lower_ & 0x4000UL) {
        my_disc.data_ |= 0x10200000ULL;
        op_disc.data_ ^= 0x10200000ULL;
        count += 2;
      }
    } else if (my_disc.lower_ & 0x200000UL) {
      my_disc.data_ |= 0x10000000ULL;
      op_disc.data_ ^= 0x10000000ULL;
      count += 1;
    }
  }
  if (op_disc.upper_ & 0x400UL) {
    if (op_disc.upper_ & 0x20000UL) {
      if (my_disc.upper_ & 0x1000000UL) {
        my_disc.data_ |= 0x2040000000000ULL;
        op_disc.data_ ^= 0x2040000000000ULL;
        count += 2;
      }
    } else if (my_disc.upper_ & 0x20000UL) {
      my_disc.data_ |= 0x40000000000ULL;
      op_disc.data_ ^= 0x40000000000ULL;
      count += 1;
    }
  }
  if (op_disc.lower_ & 0x4000000UL) {
    if (op_disc.lower_ & 0x20000UL) {
      if (my_disc.lower_ & 0x100UL) {
        my_disc.data_ |= 0x4020000ULL;
        op_disc.data_ ^= 0x4020000ULL;
        count += 2;
      }
    } else if (my_disc.lower_ & 0x20000UL) {
      my_disc.data_ |= 0x4000000ULL;
      op_disc.data_ ^= 0x4000000ULL;
      count += 1;
    }
  }
  return count;
}

static int f_44(bit_matrix& my_disc, bit_matrix& op_disc) {
  int count = 0;
  if (op_disc.upper_ & 0x20UL) {
    if (op_disc.upper_ & 0x40UL) {
      if (my_disc.upper_ & 0x80UL) {
        my_disc.data_ |= 0x6000000000ULL;
        op_disc.data_ ^= 0x6000000000ULL;
        count += 2;
      }
    } else if (my_disc.upper_ & 0x40UL) {
      my_disc.data_ |= 0x2000000000ULL;
      op_disc.data_ ^= 0x2000000000ULL;
      count += 1;
    }
  }
  if (op_disc.upper_ & 0x8UL) {
    if (op_disc.upper_ & 0x4UL) {
      if (op_disc.upper_ & 0x2UL) {
        if (my_disc.upper_ & 0x1UL) {
          my_disc.data_ |= 0xe00000000ULL;
          op_disc.data_ ^= 0xe00000000ULL;
          count += 3;
        }
      } else if (my_disc.upper_ & 0x2UL) {
        my_disc.data_ |= 0xc00000000ULL;
        op_disc.data_ ^= 0xc00000000ULL;
        count += 2;
      }
    } else if (my_disc.upper_ & 0x4UL) {
      my_disc.data_ |= 0x800000000ULL;
      op_disc.data_ ^= 0x800000000ULL;
      count += 1;
    }
  }
  if (op_disc.upper_ & 0x1000UL) {
    if (op_disc.upper_ & 0x100000UL) {
      if (my_disc.upper_ & 0x10000000UL) {
        my_disc.data_ |= 0x10100000000000ULL;
        op_disc.data_ ^= 0x10100000000000ULL;
        count += 2;
      }
    } else if (my_disc.upper_ & 0x100000UL) {
      my_disc.data_ |= 0x100000000000ULL;
      op_disc.data_ ^= 0x100000000000ULL;
      count += 1;
    }
  }
  if (op_disc.lower_ & 0x10000000UL) {
    if (op_disc.lower_ & 0x100000UL) {
      if (op_disc.lower_ & 0x1000UL) {
        if (my_disc.lower_ & 0x10UL) {
          my_disc.data_ |= 0x10101000ULL;
          op_disc.data_ ^= 0x10101000ULL;
          count += 3;
        }
      } else if (my_disc.lower_ & 0x1000UL) {
        my_disc.data_ |= 0x10100000ULL;
        op_disc.data_ ^= 0x10100000ULL;
        count += 2;
      }
    } else if (my_disc.lower_ & 0x100000UL) {
      my_disc.data_ |= 0x10000000ULL;
      op_disc.data_ ^= 0x10000000ULL;
      count += 1;
    }
  }
  if (op_disc.upper_ & 0x2000UL) {
    if (op_disc.upper_ & 0x400000UL) {
      if (my_disc.upper_ & 0x80000000UL) {
        my_disc.data_ |= 0x40200000000000ULL;
        op_disc.data_ ^= 0x40200000000000ULL;
        count += 2;
      }
    } else if (my_disc.upper_ & 0x400000UL) {
      my_disc.data_ |= 0x200000000000ULL;
      op_disc.data_ ^= 0x200000000000ULL;
      count += 1;
    }
  }
  if (op_disc.lower_ & 0x20000000UL) {
    if (op_disc.lower_ & 0x400000UL) {
      if (my_disc.lower_ & 0x8000UL) {
        my_disc.data_ |= 0x20400000ULL;
        op_disc.data_ ^= 0x20400000ULL;
        count += 2;
      }
    } else if (my_disc.lower_ & 0x400000UL) {
      my_disc.data_ |= 0x20000000ULL;
      op_disc.data_ ^= 0x20000000ULL;
      count += 1;
    }
  }
  if (op_disc.upper_ & 0x800UL) {
    if (op_disc.upper_ & 0x40000UL) {
      if (my_disc.upper_ & 0x2000000UL) {
        my_disc.data_ |= 0x4080000000000ULL;
        op_disc.data_ ^= 0x4080000000000ULL;
        count += 2;
      }
    } else if (my_disc.upper_ & 0x40000UL) {
      my_disc.data_ |= 0x80000000000ULL;
      op_disc.data_ ^= 0x80000000000ULL;
      count += 1;
    }
  }
  if (op_disc.lower_ & 0x8000000UL) {
    if (op_disc.lower_ & 0x40000UL) {
      if (op_disc.lower_ & 0x200UL) {
        if (my_disc.lower_ & 0x1UL) {
          my_disc.data_ |= 0x8040200ULL;
          op_disc.data_ ^= 0x8040200ULL;
          count += 3;
        }
      } else if (my_disc.lower_ & 0x200UL) {
        my_disc.data_ |= 0x8040000ULL;
        op_disc.data_ ^= 0x8040000ULL;
        count += 2;
      }
    } else if (my_disc.lower_ & 0x40000UL) {
      my_disc.data_ |= 0x8000000ULL;
      op_disc.data_ ^= 0x8000000ULL;
      count += 1;
    }
  }
  return count;
}

static int f_45(bit_matrix& my_disc, bit_matrix& op_disc) {
  int count = 0;
  if (op_disc.upper_ & 0x40UL) {
    if (my_disc.upper_ & 0x80UL) {
      my_disc.data_ |= 0x4000000000ULL;
      op_disc.data_ ^= 0x4000000000ULL;
      count += 1;
    }
  }
  if (op_disc.upper_ & 0x10UL) {
    if (op_disc.upper_ & 0x8UL) {
      if (op_disc.upper_ & 0x4UL) {
        if (op_disc.upper_ & 0x2UL) {
          if (my_disc.upper_ & 0x1UL) {
            my_disc.data_ |= 0x1e00000000ULL;
            op_disc.data_ ^= 0x1e00000000ULL;
            count += 4;
          }
        } else if (my_disc.upper_ & 0x2UL) {
          my_disc.data_ |= 0x1c00000000ULL;
          op_disc.data_ ^= 0x1c00000000ULL;
          count += 3;
        }
      } else if (my_disc.upper_ & 0x4UL) {
        my_disc.data_ |= 0x1800000000ULL;
        op_disc.data_ ^= 0x1800000000ULL;
        count += 2;
      }
    } else if (my_disc.upper_ & 0x8UL) {
      my_disc.data_ |= 0x1000000000ULL;
      op_disc.data_ ^= 0x1000000000ULL;
      count += 1;
    }
  }
  if (op_disc.upper_ & 0x2000UL) {
    if (op_disc.upper_ & 0x200000UL) {
      if (my_disc.upper_ & 0x20000000UL) {
        my_disc.data_ |= 0x20200000000000ULL;
        op_disc.data_ ^= 0x20200000000000ULL;
        count += 2;
      }
    } else if (my_disc.upper_ & 0x200000UL) {
      my_disc.data_ |= 0x200000000000ULL;
      op_disc.data_ ^= 0x200000000000ULL;
      count += 1;
    }
  }
  if (op_disc.lower_ & 0x20000000UL) {
    if (op_disc.lower_ & 0x200000UL) {
      if (op_disc.lower_ & 0x2000UL) {
        if (my_disc.lower_ & 0x20UL) {
          my_disc.data_ |= 0x20202000ULL;
          op_disc.data_ ^= 0x20202000ULL;
          count += 3;
        }
      } else if (my_disc.lower_ & 0x2000UL) {
        my_disc.data_ |= 0x20200000ULL;
        op_disc.data_ ^= 0x20200000ULL;
        count += 2;
      }
    } else if (my_disc.lower_ & 0x200000UL) {
      my_disc.data_ |= 0x20000000ULL;
      op_disc.data_ ^= 0x20000000ULL;
      count += 1;
    }
  }
  if (op_disc.upper_ & 0x4000UL) {
    if (my_disc.upper_ & 0x800000UL) {
      my_disc.data_ |= 0x400000000000ULL;
      op_disc.data_ ^= 0x400000000000ULL;
      count += 1;
    }
  }
  if (op_disc.lower_ & 0x40000000UL) {
    if (my_disc.lower_ & 0x800000UL) {
      my_disc.data_ |= 0x40000000ULL;
      op_disc.data_ ^= 0x40000000ULL;
      count += 1;
    }
  }
  if (op_disc.upper_ & 0x1000UL) {
    if (op_disc.upper_ & 0x80000UL) {
      if (my_disc.upper_ & 0x4000000UL) {
        my_disc.data_ |= 0x8100000000000ULL;
        op_disc.data_ ^= 0x8100000000000ULL;
        count += 2;
      }
    } else if (my_disc.upper_ & 0x80000UL) {
      my_disc.data_ |= 0x100000000000ULL;
      op_disc.data_ ^= 0x100000000000ULL;
      count += 1;
    }
  }
  if (op_disc.lower_ & 0x10000000UL) {
    if (op_disc.lower_ & 0x80000UL) {
      if (op_disc.lower_ & 0x400UL) {
        if (my_disc.lower_ & 0x2UL) {
          my_disc.data_ |= 0x10080400ULL;
          op_disc.data_ ^= 0x10080400ULL;
          count += 3;
        }
      } else if (my_disc.lower_ & 0x400UL) {
        my_disc.data_ |= 0x10080000ULL;
        op_disc.data_ ^= 0x10080000ULL;
        count += 2;
      }
    } else if (my_disc.lower_ & 0x80000UL) {
      my_disc.data_ |= 0x10000000ULL;
      op_disc.data_ ^= 0x10000000ULL;
      count += 1;
    }
  }
  return count;
}

static int f_46(bit_matrix& my_disc, bit_matrix& op_disc) {
  int count = 0;
  if (op_disc.upper_ & 0x20UL) {
    if (op_disc.upper_ & 0x10UL) {
      if (op_disc.upper_ & 0x8UL) {
        if (op_disc.upper_ & 0x4UL) {
          if (op_disc.upper_ & 0x2UL) {
            if (my_disc.upper_ & 0x1UL) {
              my_disc.data_ |= 0x3e00000000ULL;
              op_disc.data_ ^= 0x3e00000000ULL;
              count += 5;
            }
          } else if (my_disc.upper_ & 0x2UL) {
            my_disc.data_ |= 0x3c00000000ULL;
            op_disc.data_ ^= 0x3c00000000ULL;
            count += 4;
          }
        } else if (my_disc.upper_ & 0x4UL) {
          my_disc.data_ |= 0x3800000000ULL;
          op_disc.data_ ^= 0x3800000000ULL;
          count += 3;
        }
      } else if (my_disc.upper_ & 0x8UL) {
        my_disc.data_ |= 0x3000000000ULL;
        op_disc.data_ ^= 0x3000000000ULL;
        count += 2;
      }
    } else if (my_disc.upper_ & 0x10UL) {
      my_disc.data_ |= 0x2000000000ULL;
      op_disc.data_ ^= 0x2000000000ULL;
      count += 1;
    }
  }
  if (op_disc.upper_ & 0x4000UL) {
    if (op_disc.upper_ & 0x400000UL) {
      if (my_disc.upper_ & 0x40000000UL) {
        my_disc.data_ |= 0x40400000000000ULL;
        op_disc.data_ ^= 0x40400000000000ULL;
        count += 2;
      }
    } else if (my_disc.upper_ & 0x400000UL) {
      my_disc.data_ |= 0x400000000000ULL;
      op_disc.data_ ^= 0x400000000000ULL;
      count += 1;
    }
  }
  if (op_disc.lower_ & 0x40000000UL) {
    if (op_disc.lower_ & 0x400000UL) {
      if (op_disc.lower_ & 0x4000UL) {
        if (my_disc.lower_ & 0x40UL) {
          my_disc.data_ |= 0x40404000ULL;
          op_disc.data_ ^= 0x40404000ULL;
          count += 3;
        }
      } else if (my_disc.lower_ & 0x4000UL) {
        my_disc.data_ |= 0x40400000ULL;
        op_disc.data_ ^= 0x40400000ULL;
        count += 2;
      }
    } else if (my_disc.lower_ & 0x400000UL) {
      my_disc.data_ |= 0x40000000ULL;
      op_disc.data_ ^= 0x40000000ULL;
      count += 1;
    }
  }
  if (op_disc.upper_ & 0x2000UL) {
    if (op_disc.upper_ & 0x100000UL) {
      if (my_disc.upper_ & 0x8000000UL) {
        my_disc.data_ |= 0x10200000000000ULL;
        op_disc.data_ ^= 0x10200000000000ULL;
        count += 2;
      }
    } else if (my_disc.upper_ & 0x100000UL) {
      my_disc.data_ |= 0x200000000000ULL;
      op_disc.data_ ^= 0x200000000000ULL;
      count += 1;
    }
  }
  if (op_disc.lower_ & 0x20000000UL) {
    if (op_disc.lower_ & 0x100000UL) {
      if (op_disc.lower_ & 0x800UL) {
        if (my_disc.lower_ & 0x4UL) {
          my_disc.data_ |= 0x20100800ULL;
          op_disc.data_ ^= 0x20100800ULL;
          count += 3;
        }
      } else if (my_disc.lower_ & 0x800UL) {
        my_disc.data_ |= 0x20100000ULL;
        op_disc.data_ ^= 0x20100000ULL;
        count += 2;
      }
    } else if (my_disc.lower_ & 0x100000UL) {
      my_disc.data_ |= 0x20000000ULL;
      op_disc.data_ ^= 0x20000000ULL;
      count += 1;
    }
  }
  return count;
}

static int f_47(bit_matrix& my_disc, bit_matrix& op_disc) {
  int count = 0;
  if (op_disc.upper_ & 0x40UL) {
    if (op_disc.upper_ & 0x20UL) {
      if (op_disc.upper_ & 0x10UL) {
        if (op_disc.upper_ & 0x8UL) {
          if (op_disc.upper_ & 0x4UL) {
            if (op_disc.upper_ & 0x2UL) {
              if (my_disc.upper_ & 0x1UL) {
                my_disc.data_ |= 0x7e00000000ULL;
                op_disc.data_ ^= 0x7e00000000ULL;
                count += 6;
              }
            } else if (my_disc.upper_ & 0x2UL) {
              my_disc.data_ |= 0x7c00000000ULL;
              op_disc.data_ ^= 0x7c00000000ULL;
              count += 5;
            }
          } else if (my_disc.upper_ & 0x4UL) {
            my_disc.data_ |= 0x7800000000ULL;
            op_disc.data_ ^= 0x7800000000ULL;
            count += 4;
          }
        } else if (my_disc.upper_ & 0x8UL) {
          my_disc.data_ |= 0x7000000000ULL;
          op_disc.data_ ^= 0x7000000000ULL;
          count += 3;
        }
      } else if (my_disc.upper_ & 0x10UL) {
        my_disc.data_ |= 0x6000000000ULL;
        op_disc.data_ ^= 0x6000000000ULL;
        count += 2;
      }
    } else if (my_disc.upper_ & 0x20UL) {
      my_disc.data_ |= 0x4000000000ULL;
      op_disc.data_ ^= 0x4000000000ULL;
      count += 1;
    }
  }
  if (op_disc.upper_ & 0x8000UL) {
    if (op_disc.upper_ & 0x800000UL) {
      if (my_disc.upper_ & 0x80000000UL) {
        my_disc.data_ |= 0x80800000000000ULL;
        op_disc.data_ ^= 0x80800000000000ULL;
        count += 2;
      }
    } else if (my_disc.upper_ & 0x800000UL) {
      my_disc.data_ |= 0x800000000000ULL;
      op_disc.data_ ^= 0x800000000000ULL;
      count += 1;
    }
  }
  if (op_disc.lower_ & 0x80000000UL) {
    if (op_disc.lower_ & 0x800000UL) {
      if (op_disc.lower_ & 0x8000UL) {
        if (my_disc.lower_ & 0x80UL) {
          my_disc.data_ |= 0x80808000ULL;
          op_disc.data_ ^= 0x80808000ULL;
          count += 3;
        }
      } else if (my_disc.lower_ & 0x8000UL) {
        my_disc.data_ |= 0x80800000ULL;
        op_disc.data_ ^= 0x80800000ULL;
        count += 2;
      }
    } else if (my_disc.lower_ & 0x800000UL) {
      my_disc.data_ |= 0x80000000ULL;
      op_disc.data_ ^= 0x80000000ULL;
      count += 1;
    }
  }
  if (op_disc.upper_ & 0x4000UL) {
    if (op_disc.upper_ & 0x200000UL) {
      if (my_disc.upper_ & 0x10000000UL) {
        my_disc.data_ |= 0x20400000000000ULL;
        op_disc.data_ ^= 0x20400000000000ULL;
        count += 2;
      }
    } else if (my_disc.upper_ & 0x200000UL) {
      my_disc.data_ |= 0x400000000000ULL;
      op_disc.data_ ^= 0x400000000000ULL;
      count += 1;
    }
  }
  if (op_disc.lower_ & 0x40000000UL) {
    if (op_disc.lower_ & 0x200000UL) {
      if (op_disc.lower_ & 0x1000UL) {
        if (my_disc.lower_ & 0x8UL) {
          my_disc.data_ |= 0x40201000ULL;
          op_disc.data_ ^= 0x40201000ULL;
          count += 3;
        }
      } else if (my_disc.lower_ & 0x1000UL) {
        my_disc.data_ |= 0x40200000ULL;
        op_disc.data_ ^= 0x40200000ULL;
        count += 2;
      }
    } else if (my_disc.lower_ & 0x200000UL) {
      my_disc.data_ |= 0x40000000ULL;
      op_disc.data_ ^= 0x40000000ULL;
      count += 1;
    }
  }
  return count;
}

static int f_50(bit_matrix& my_disc, bit_matrix& op_disc) {
  int count = 0;
  if (op_disc.upper_ & 0x200UL) {
    if (op_disc.upper_ & 0x400UL) {
      if (op_disc.upper_ & 0x800UL) {
        if (op_disc.upper_ & 0x1000UL) {
          if (op_disc.upper_ & 0x2000UL) {
            if (op_disc.upper_ & 0x4000UL) {
              if (my_disc.upper_ & 0x8000UL) {
                my_disc.data_ |= 0x7e0000000000ULL;
                op_disc.data_ ^= 0x7e0000000000ULL;
                count += 6;
              }
            } else if (my_disc.upper_ & 0x4000UL) {
              my_disc.data_ |= 0x3e0000000000ULL;
              op_disc.data_ ^= 0x3e0000000000ULL;
              count += 5;
            }
          } else if (my_disc.upper_ & 0x2000UL) {
            my_disc.data_ |= 0x1e0000000000ULL;
            op_disc.data_ ^= 0x1e0000000000ULL;
            count += 4;
          }
        } else if (my_disc.upper_ & 0x1000UL) {
          my_disc.data_ |= 0xe0000000000ULL;
          op_disc.data_ ^= 0xe0000000000ULL;
          count += 3;
        }
      } else if (my_disc.upper_ & 0x800UL) {
        my_disc.data_ |= 0x60000000000ULL;
        op_disc.data_ ^= 0x60000000000ULL;
        count += 2;
      }
    } else if (my_disc.upper_ & 0x400UL) {
      my_disc.data_ |= 0x20000000000ULL;
      op_disc.data_ ^= 0x20000000000ULL;
      count += 1;
    }
  }
  if (op_disc.upper_ & 0x10000UL) {
    if (my_disc.upper_ & 0x1000000UL) {
      my_disc.data_ |= 0x1000000000000ULL;
      op_disc.data_ ^= 0x1000000000000ULL;
      count += 1;
    }
  }
  if (op_disc.upper_ & 0x1UL) {
    if (op_disc.lower_ & 0x1000000UL) {
      if (op_disc.lower_ & 0x10000UL) {
        if (op_disc.lower_ & 0x100UL) {
          if (my_disc.lower_ & 0x1UL) {
            my_disc.data_ |= 0x101010100ULL;
            op_disc.data_ ^= 0x101010100ULL;
            count += 4;
          }
        } else if (my_disc.lower_ & 0x100UL) {
          my_disc.data_ |= 0x101010000ULL;
          op_disc.data_ ^= 0x101010000ULL;
          count += 3;
        }
      } else if (my_disc.lower_ & 0x10000UL) {
        my_disc.data_ |= 0x101000000ULL;
        op_disc.data_ ^= 0x101000000ULL;
        count += 2;
      }
    } else if (my_disc.lower_ & 0x1000000UL) {
      my_disc.data_ |= 0x100000000ULL;
      op_disc.data_ ^= 0x100000000ULL;
      count += 1;
    }
  }
  if (op_disc.upper_ & 0x20000UL) {
    if (my_disc.upper_ & 0x4000000UL) {
      my_disc.data_ |= 0x2000000000000ULL;
      op_disc.data_ ^= 0x2000000000000ULL;
      count += 1;
    }
  }
  if (op_disc.upper_ & 0x2UL) {
    if (op_disc.lower_ & 0x4000000UL) {
      if (op_disc.lower_ & 0x80000UL) {
        if (op_disc.lower_ & 0x1000UL) {
          if (my_disc.lower_ & 0x20UL) {
            my_disc.data_ |= 0x204081000ULL;
            op_disc.data_ ^= 0x204081000ULL;
            count += 4;
          }
        } else if (my_disc.lower_ & 0x1000UL) {
          my_disc.data_ |= 0x204080000ULL;
          op_disc.data_ ^= 0x204080000ULL;
          count += 3;
        }
      } else if (my_disc.lower_ & 0x80000UL) {
        my_disc.data_ |= 0x204000000ULL;
        op_disc.data_ ^= 0x204000000ULL;
        count += 2;
      }
    } else if (my_disc.lower_ & 0x4000000UL) {
      my_disc.data_ |= 0x200000000ULL;
      op_disc.data_ ^= 0x200000000ULL;
      count += 1;
    }
  }
  return count;
}

static int f_51(bit_matrix& my_disc, bit_matrix& op_disc) {
  int count = 0;
  if (op_disc.upper_ & 0x400UL) {
    if (op_disc.upper_ & 0x800UL) {
      if (op_disc.upper_ & 0x1000UL) {
        if (op_disc.upper_ & 0x2000UL) {
          if (op_disc.upper_ & 0x4000UL) {
            if (my_disc.upper_ & 0x8000UL) {
              my_disc.data_ |= 0x7c0000000000ULL;
              op_disc.data_ ^= 0x7c0000000000ULL;
              count += 5;
            }
          } else if (my_disc.upper_ & 0x4000UL) {
            my_disc.data_ |= 0x3c0000000000ULL;
            op_disc.data_ ^= 0x3c0000000000ULL;
            count += 4;
          }
        } else if (my_disc.upper_ & 0x2000UL) {
          my_disc.data_ |= 0x1c0000000000ULL;
          op_disc.data_ ^= 0x1c0000000000ULL;
          count += 3;
        }
      } else if (my_disc.upper_ & 0x1000UL) {
        my_disc.data_ |= 0xc0000000000ULL;
        op_disc.data_ ^= 0xc0000000000ULL;
        count += 2;
      }
    } else if (my_disc.upper_ & 0x800UL) {
      my_disc.data_ |= 0x40000000000ULL;
      op_disc.data_ ^= 0x40000000000ULL;
      count += 1;
    }
  }
  if (op_disc.upper_ & 0x20000UL) {
    if (my_disc.upper_ & 0x2000000UL) {
      my_disc.data_ |= 0x2000000000000ULL;
      op_disc.data_ ^= 0x2000000000000ULL;
      count += 1;
    }
  }
  if (op_disc.upper_ & 0x2UL) {
    if (op_disc.lower_ & 0x2000000UL) {
      if (op_disc.lower_ & 0x20000UL) {
        if (op_disc.lower_ & 0x200UL) {
          if (my_disc.lower_ & 0x2UL) {
            my_disc.data_ |= 0x202020200ULL;
            op_disc.data_ ^= 0x202020200ULL;
            count += 4;
          }
        } else if (my_disc.lower_ & 0x200UL) {
          my_disc.data_ |= 0x202020000ULL;
          op_disc.data_ ^= 0x202020000ULL;
          count += 3;
        }
      } else if (my_disc.lower_ & 0x20000UL) {
        my_disc.data_ |= 0x202000000ULL;
        op_disc.data_ ^= 0x202000000ULL;
        count += 2;
      }
    } else if (my_disc.lower_ & 0x2000000UL) {
      my_disc.data_ |= 0x200000000ULL;
      op_disc.data_ ^= 0x200000000ULL;
      count += 1;
    }
  }
  if (op_disc.upper_ & 0x40000UL) {
    if (my_disc.upper_ & 0x8000000UL) {
      my_disc.data_ |= 0x4000000000000ULL;
      op_disc.data_ ^= 0x4000000000000ULL;
      count += 1;
    }
  }
  if (op_disc.upper_ & 0x4UL) {
    if (op_disc.lower_ & 0x8000000UL) {
      if (op_disc.lower_ & 0x100000UL) {
        if (op_disc.lower_ & 0x2000UL) {
          if (my_disc.lower_ & 0x40UL) {
            my_disc.data_ |= 0x408102000ULL;
            op_disc.data_ ^= 0x408102000ULL;
            count += 4;
          }
        } else if (my_disc.lower_ & 0x2000UL) {
          my_disc.data_ |= 0x408100000ULL;
          op_disc.data_ ^= 0x408100000ULL;
          count += 3;
        }
      } else if (my_disc.lower_ & 0x100000UL) {
        my_disc.data_ |= 0x408000000ULL;
        op_disc.data_ ^= 0x408000000ULL;
        count += 2;
      }
    } else if (my_disc.lower_ & 0x8000000UL) {
      my_disc.data_ |= 0x400000000ULL;
      op_disc.data_ ^= 0x400000000ULL;
      count += 1;
    }
  }
  return count;
}

static int f_52(bit_matrix& my_disc, bit_matrix& op_disc) {
  int count = 0;
  if (op_disc.upper_ & 0x800UL) {
    if (op_disc.upper_ & 0x1000UL) {
      if (op_disc.upper_ & 0x2000UL) {
        if (op_disc.upper_ & 0x4000UL) {
          if (my_disc.upper_ & 0x8000UL) {
            my_disc.data_ |= 0x780000000000ULL;
            op_disc.data_ ^= 0x780000000000ULL;
            count += 4;
          }
        } else if (my_disc.upper_ & 0x4000UL) {
          my_disc.data_ |= 0x380000000000ULL;
          op_disc.data_ ^= 0x380000000000ULL;
          count += 3;
        }
      } else if (my_disc.upper_ & 0x2000UL) {
        my_disc.data_ |= 0x180000000000ULL;
        op_disc.data_ ^= 0x180000000000ULL;
        count += 2;
      }
    } else if (my_disc.upper_ & 0x1000UL) {
      my_disc.data_ |= 0x80000000000ULL;
      op_disc.data_ ^= 0x80000000000ULL;
      count += 1;
    }
  }
  if (op_disc.upper_ & 0x200UL) {
    if (my_disc.upper_ & 0x100UL) {
      my_disc.data_ |= 0x20000000000ULL;
      op_disc.data_ ^= 0x20000000000ULL;
      count += 1;
    }
  }
  if (op_disc.upper_ & 0x40000UL) {
    if (my_disc.upper_ & 0x4000000UL) {
      my_disc.data_ |= 0x4000000000000ULL;
      op_disc.data_ ^= 0x4000000000000ULL;
      count += 1;
    }
  }
  if (op_disc.upper_ & 0x4UL) {
    if (op_disc.lower_ & 0x4000000UL) {
      if (op_disc.lower_ & 0x40000UL) {
        if (op_disc.lower_ & 0x400UL) {
          if (my_disc.lower_ & 0x4UL) {
            my_disc.data_ |= 0x404040400ULL;
            op_disc.data_ ^= 0x404040400ULL;
            count += 4;
          }
        } else if (my_disc.lower_ & 0x400UL) {
          my_disc.data_ |= 0x404040000ULL;
          op_disc.data_ ^= 0x404040000ULL;
          count += 3;
        }
      } else if (my_disc.lower_ & 0x40000UL) {
        my_disc.data_ |= 0x404000000ULL;
        op_disc.data_ ^= 0x404000000ULL;
        count += 2;
      }
    } else if (my_disc.lower_ & 0x4000000UL) {
      my_disc.data_ |= 0x400000000ULL;
      op_disc.data_ ^= 0x400000000ULL;
      count += 1;
    }
  }
  if (op_disc.upper_ & 0x80000UL) {
    if (my_disc.upper_ & 0x10000000UL) {
      my_disc.data_ |= 0x8000000000000ULL;
      op_disc.data_ ^= 0x8000000000000ULL;
      count += 1;
    }
  }
  if (op_disc.upper_ & 0x8UL) {
    if (op_disc.lower_ & 0x10000000UL) {
      if (op_disc.lower_ & 0x200000UL) {
        if (op_disc.lower_ & 0x4000UL) {
          if (my_disc.lower_ & 0x80UL) {
            my_disc.data_ |= 0x810204000ULL;
            op_disc.data_ ^= 0x810204000ULL;
            count += 4;
          }
        } else if (my_disc.lower_ & 0x4000UL) {
          my_disc.data_ |= 0x810200000ULL;
          op_disc.data_ ^= 0x810200000ULL;
          count += 3;
        }
      } else if (my_disc.lower_ & 0x200000UL) {
        my_disc.data_ |= 0x810000000ULL;
        op_disc.data_ ^= 0x810000000ULL;
        count += 2;
      }
    } else if (my_disc.lower_ & 0x10000000UL) {
      my_disc.data_ |= 0x800000000ULL;
      op_disc.data_ ^= 0x800000000ULL;
      count += 1;
    }
  }
  if (op_disc.upper_ & 0x20000UL) {
    if (my_disc.upper_ & 0x1000000UL) {
      my_disc.data_ |= 0x2000000000000ULL;
      op_disc.data_ ^= 0x2000000000000ULL;
      count += 1;
    }
  }
  if (op_disc.upper_ & 0x2UL) {
    if (my_disc.lower_ & 0x1000000UL) {
      my_disc.data_ |= 0x200000000ULL;
      op_disc.data_ ^= 0x200000000ULL;
      count += 1;
    }
  }
  return count;
}

static int f_53(bit_matrix& my_disc, bit_matrix& op_disc) {
  int count = 0;
  if (op_disc.upper_ & 0x1000UL) {
    if (op_disc.upper_ & 0x2000UL) {
      if (op_disc.upper_ & 0x4000UL) {
        if (my_disc.upper_ & 0x8000UL) {
          my_disc.data_ |= 0x700000000000ULL;
          op_disc.data_ ^= 0x700000000000ULL;
          count += 3;
        }
      } else if (my_disc.upper_ & 0x4000UL) {
        my_disc.data_ |= 0x300000000000ULL;
        op_disc.data_ ^= 0x300000000000ULL;
        count += 2;
      }
    } else if (my_disc.upper_ & 0x2000UL) {
      my_disc.data_ |= 0x100000000000ULL;
      op_disc.data_ ^= 0x100000000000ULL;
      count += 1;
    }
  }
  if (op_disc.upper_ & 0x400UL) {
    if (op_disc.upper_ & 0x200UL) {
      if (my_disc.upper_ & 0x100UL) {
        my_disc.data_ |= 0x60000000000ULL;
        op_disc.data_ ^= 0x60000000000ULL;
        count += 2;
      }
    } else if (my_disc.upper_ & 0x200UL) {
      my_disc.data_ |= 0x40000000000ULL;
      op_disc.data_ ^= 0x40000000000ULL;
      count += 1;
    }
  }
  if (op_disc.upper_ & 0x80000UL) {
    if (my_disc.upper_ & 0x8000000UL) {
      my_disc.data_ |= 0x8000000000000ULL;
      op_disc.data_ ^= 0x8000000000000ULL;
      count += 1;
    }
  }
  if (op_disc.upper_ & 0x8UL) {
    if (op_disc.lower_ & 0x8000000UL) {
      if (op_disc.lower_ & 0x80000UL) {
        if (op_disc.lower_ & 0x800UL) {
          if (my_disc.lower_ & 0x8UL) {
            my_disc.data_ |= 0x808080800ULL;
            op_disc.data_ ^= 0x808080800ULL;
            count += 4;
          }
        } else if (my_disc.lower_ & 0x800UL) {
          my_disc.data_ |= 0x808080000ULL;
          op_disc.data_ ^= 0x808080000ULL;
          count += 3;
        }
      } else if (my_disc.lower_ & 0x80000UL) {
        my_disc.data_ |= 0x808000000ULL;
        op_disc.data_ ^= 0x808000000ULL;
        count += 2;
      }
    } else if (my_disc.lower_ & 0x8000000UL) {
      my_disc.data_ |= 0x800000000ULL;
      op_disc.data_ ^= 0x800000000ULL;
      count += 1;
    }
  }
  if (op_disc.upper_ & 0x100000UL) {
    if (my_disc.upper_ & 0x20000000UL) {
      my_disc.data_ |= 0x10000000000000ULL;
      op_disc.data_ ^= 0x10000000000000ULL;
      count += 1;
    }
  }
  if (op_disc.upper_ & 0x10UL) {
    if (op_disc.lower_ & 0x20000000UL) {
      if (op_disc.lower_ & 0x400000UL) {
        if (my_disc.lower_ & 0x8000UL) {
          my_disc.data_ |= 0x1020400000ULL;
          op_disc.data_ ^= 0x1020400000ULL;
          count += 3;
        }
      } else if (my_disc.lower_ & 0x400000UL) {
        my_disc.data_ |= 0x1020000000ULL;
        op_disc.data_ ^= 0x1020000000ULL;
        count += 2;
      }
    } else if (my_disc.lower_ & 0x20000000UL) {
      my_disc.data_ |= 0x1000000000ULL;
      op_disc.data_ ^= 0x1000000000ULL;
      count += 1;
    }
  }
  if (op_disc.upper_ & 0x40000UL) {
    if (my_disc.upper_ & 0x2000000UL) {
      my_disc.data_ |= 0x4000000000000ULL;
      op_disc.data_ ^= 0x4000000000000ULL;
      count += 1;
    }
  }
  if (op_disc.upper_ & 0x4UL) {
    if (op_disc.lower_ & 0x2000000UL) {
      if (my_disc.lower_ & 0x10000UL) {
        my_disc.data_ |= 0x402000000ULL;
        op_disc.data_ ^= 0x402000000ULL;
        count += 2;
      }
    } else if (my_disc.lower_ & 0x2000000UL) {
      my_disc.data_ |= 0x400000000ULL;
      op_disc.data_ ^= 0x400000000ULL;
      count += 1;
    }
  }
  return count;
}

static int f_54(bit_matrix& my_disc, bit_matrix& op_disc) {
  int count = 0;
  if (op_disc.upper_ & 0x2000UL) {
    if (op_disc.upper_ & 0x4000UL) {
      if (my_disc.upper_ & 0x8000UL) {
        my_disc.data_ |= 0x600000000000ULL;
        op_disc.data_ ^= 0x600000000000ULL;
        count += 2;
      }
    } else if (my_disc.upper_ & 0x4000UL) {
      my_disc.data_ |= 0x200000000000ULL;
      op_disc.data_ ^= 0x200000000000ULL;
      count += 1;
    }
  }
  if (op_disc.upper_ & 0x800UL) {
    if (op_disc.upper_ & 0x400UL) {
      if (op_disc.upper_ & 0x200UL) {
        if (my_disc.upper_ & 0x100UL) {
          my_disc.data_ |= 0xe0000000000ULL;
          op_disc.data_ ^= 0xe0000000000ULL;
          count += 3;
        }
      } else if (my_disc.upper_ & 0x200UL) {
        my_disc.data_ |= 0xc0000000000ULL;
        op_disc.data_ ^= 0xc0000000000ULL;
        count += 2;
      }
    } else if (my_disc.upper_ & 0x400UL) {
      my_disc.data_ |= 0x80000000000ULL;
      op_disc.data_ ^= 0x80000000000ULL;
      count += 1;
    }
  }
  if (op_disc.upper_ & 0x100000UL) {
    if (my_disc.upper_ & 0x10000000UL) {
      my_disc.data_ |= 0x10000000000000ULL;
      op_disc.data_ ^= 0x10000000000000ULL;
      count += 1;
    }
  }
  if (op_disc.upper_ & 0x10UL) {
    if (op_disc.lower_ & 0x10000000UL) {
      if (op_disc.lower_ & 0x100000UL) {
        if (op_disc.lower_ & 0x1000UL) {
          if (my_disc.lower_ & 0x10UL) {
            my_disc.data_ |= 0x1010101000ULL;
            op_disc.data_ ^= 0x1010101000ULL;
            count += 4;
          }
        } else if (my_disc.lower_ & 0x1000UL) {
          my_disc.data_ |= 0x1010100000ULL;
          op_disc.data_ ^= 0x1010100000ULL;
          count += 3;
        }
      } else if (my_disc.lower_ & 0x100000UL) {
        my_disc.data_ |= 0x1010000000ULL;
        op_disc.data_ ^= 0x1010000000ULL;
        count += 2;
      }
    } else if (my_disc.lower_ & 0x10000000UL) {
      my_disc.data_ |= 0x1000000000ULL;
      op_disc.data_ ^= 0x1000000000ULL;
      count += 1;
    }
  }
  if (op_disc.upper_ & 0x200000UL) {
    if (my_disc.upper_ & 0x40000000UL) {
      my_disc.data_ |= 0x20000000000000ULL;
      op_disc.data_ ^= 0x20000000000000ULL;
      count += 1;
    }
  }
  if (op_disc.upper_ & 0x20UL) {
    if (op_disc.lower_ & 0x40000000UL) {
      if (my_disc.lower_ & 0x800000UL) {
        my_disc.data_ |= 0x2040000000ULL;
        op_disc.data_ ^= 0x2040000000ULL;
        count += 2;
      }
    } else if (my_disc.lower_ & 0x40000000UL) {
      my_disc.data_ |= 0x2000000000ULL;
      op_disc.data_ ^= 0x2000000000ULL;
      count += 1;
    }
  }
  if (op_disc.upper_ & 0x80000UL) {
    if (my_disc.upper_ & 0x4000000UL) {
      my_disc.data_ |= 0x8000000000000ULL;
      op_disc.data_ ^= 0x8000000000000ULL;
      count += 1;
    }
  }
  if (op_disc.upper_ & 0x8UL) {
    if (op_disc.lower_ & 0x4000000UL) {
      if (op_disc.lower_ & 0x20000UL) {
        if (my_disc.lower_ & 0x100UL) {
          my_disc.data_ |= 0x804020000ULL;
          op_disc.data_ ^= 0x804020000ULL;
          count += 3;
        }
      } else if (my_disc.lower_ & 0x20000UL) {
        my_disc.data_ |= 0x804000000ULL;
        op_disc.data_ ^= 0x804000000ULL;
        count += 2;
      }
    } else if (my_disc.lower_ & 0x4000000UL) {
      my_disc.data_ |= 0x800000000ULL;
      op_disc.data_ ^= 0x800000000ULL;
      count += 1;
    }
  }
  return count;
}

static int f_55(bit_matrix& my_disc, bit_matrix& op_disc) {
  int count = 0;
  if (op_disc.upper_ & 0x4000UL) {
    if (my_disc.upper_ & 0x8000UL) {
      my_disc.data_ |= 0x400000000000ULL;
      op_disc.data_ ^= 0x400000000000ULL;
      count += 1;
    }
  }
  if (op_disc.upper_ & 0x1000UL) {
    if (op_disc.upper_ & 0x800UL) {
      if (op_disc.upper_ & 0x400UL) {
        if (op_disc.upper_ & 0x200UL) {
          if (my_disc.upper_ & 0x100UL) {
            my_disc.data_ |= 0x1e0000000000ULL;
            op_disc.data_ ^= 0x1e0000000000ULL;
            count += 4;
          }
        } else if (my_disc.upper_ & 0x200UL) {
          my_disc.data_ |= 0x1c0000000000ULL;
          op_disc.data_ ^= 0x1c0000000000ULL;
          count += 3;
        }
      } else if (my_disc.upper_ & 0x400UL) {
        my_disc.data_ |= 0x180000000000ULL;
        op_disc.data_ ^= 0x180000000000ULL;
        count += 2;
      }
    } else if (my_disc.upper_ & 0x800UL) {
      my_disc.data_ |= 0x100000000000ULL;
      op_disc.data_ ^= 0x100000000000ULL;
      count += 1;
    }
  }
  if (op_disc.upper_ & 0x200000UL) {
    if (my_disc.upper_ & 0x20000000UL) {
      my_disc.data_ |= 0x20000000000000ULL;
      op_disc.data_ ^= 0x20000000000000ULL;
      count += 1;
    }
  }
  if (op_disc.upper_ & 0x20UL) {
    if (op_disc.lower_ & 0x20000000UL) {
      if (op_disc.lower_ & 0x200000UL) {
        if (op_disc.lower_ & 0x2000UL) {
          if (my_disc.lower_ & 0x20UL) {
            my_disc.data_ |= 0x2020202000ULL;
            op_disc.data_ ^= 0x2020202000ULL;
            count += 4;
          }
        } else if (my_disc.lower_ & 0x2000UL) {
          my_disc.data_ |= 0x2020200000ULL;
          op_disc.data_ ^= 0x2020200000ULL;
          count += 3;
        }
      } else if (my_disc.lower_ & 0x200000UL) {
        my_disc.data_ |= 0x2020000000ULL;
        op_disc.data_ ^= 0x2020000000ULL;
        count += 2;
      }
    } else if (my_disc.lower_ & 0x20000000UL) {
      my_disc.data_ |= 0x2000000000ULL;
      op_disc.data_ ^= 0x2000000000ULL;
      count += 1;
    }
  }
  if (op_disc.upper_ & 0x400000UL) {
    if (my_disc.upper_ & 0x80000000UL) {
      my_disc.data_ |= 0x40000000000000ULL;
      op_disc.data_ ^= 0x40000000000000ULL;
      count += 1;
    }
  }
  if (op_disc.upper_ & 0x40UL) {
    if (my_disc.lower_ & 0x80000000UL) {
      my_disc.data_ |= 0x4000000000ULL;
      op_disc.data_ ^= 0x4000000000ULL;
      count += 1;
    }
  }
  if (op_disc.upper_ & 0x100000UL) {
    if (my_disc.upper_ & 0x8000000UL) {
      my_disc.data_ |= 0x10000000000000ULL;
      op_disc.data_ ^= 0x10000000000000ULL;
      count += 1;
    }
  }
  if (op_disc.upper_ & 0x10UL) {
    if (op_disc.lower_ & 0x8000000UL) {
      if (op_disc.lower_ & 0x40000UL) {
        if (op_disc.lower_ & 0x200UL) {
          if (my_disc.lower_ & 0x1UL) {
            my_disc.data_ |= 0x1008040200ULL;
            op_disc.data_ ^= 0x1008040200ULL;
            count += 4;
          }
        } else if (my_disc.lower_ & 0x200UL) {
          my_disc.data_ |= 0x1008040000ULL;
          op_disc.data_ ^= 0x1008040000ULL;
          count += 3;
        }
      } else if (my_disc.lower_ & 0x40000UL) {
        my_disc.data_ |= 0x1008000000ULL;
        op_disc.data_ ^= 0x1008000000ULL;
        count += 2;
      }
    } else if (my_disc.lower_ & 0x8000000UL) {
      my_disc.data_ |= 0x1000000000ULL;
      op_disc.data_ ^= 0x1000000000ULL;
      count += 1;
    }
  }
  return count;
}

static int f_56(bit_matrix& my_disc, bit_matrix& op_disc) {
  int count = 0;
  if (op_disc.upper_ & 0x2000UL) {
    if (op_disc.upper_ & 0x1000UL) {
      if (op_disc.upper_ & 0x800UL) {
        if (op_disc.upper_ & 0x400UL) {
          if (op_disc.upper_ & 0x200UL) {
            if (my_disc.upper_ & 0x100UL) {
              my_disc.data_ |= 0x3e0000000000ULL;
              op_disc.data_ ^= 0x3e0000000000ULL;
              count += 5;
            }
          } else if (my_disc.upper_ & 0x200UL) {
            my_disc.data_ |= 0x3c0000000000ULL;
            op_disc.data_ ^= 0x3c0000000000ULL;
            count += 4;
          }
        } else if (my_disc.upper_ & 0x400UL) {
          my_disc.data_ |= 0x380000000000ULL;
          op_disc.data_ ^= 0x380000000000ULL;
          count += 3;
        }
      } else if (my_disc.upper_ & 0x800UL) {
        my_disc.data_ |= 0x300000000000ULL;
        op_disc.data_ ^= 0x300000000000ULL;
        count += 2;
      }
    } else if (my_disc.upper_ & 0x1000UL) {
      my_disc.data_ |= 0x200000000000ULL;
      op_disc.data_ ^= 0x200000000000ULL;
      count += 1;
    }
  }
  if (op_disc.upper_ & 0x400000UL) {
    if (my_disc.upper_ & 0x40000000UL) {
      my_disc.data_ |= 0x40000000000000ULL;
      op_disc.data_ ^= 0x40000000000000ULL;
      count += 1;
    }
  }
  if (op_disc.upper_ & 0x40UL) {
    if (op_disc.lower_ & 0x40000000UL) {
      if (op_disc.lower_ & 0x400000UL) {
        if (op_disc.lower_ & 0x4000UL) {
          if (my_disc.lower_ & 0x40UL) {
            my_disc.data_ |= 0x4040404000ULL;
            op_disc.data_ ^= 0x4040404000ULL;
            count += 4;
          }
        } else if (my_disc.lower_ & 0x4000UL) {
          my_disc.data_ |= 0x4040400000ULL;
          op_disc.data_ ^= 0x4040400000ULL;
          count += 3;
        }
      } else if (my_disc.lower_ & 0x400000UL) {
        my_disc.data_ |= 0x4040000000ULL;
        op_disc.data_ ^= 0x4040000000ULL;
        count += 2;
      }
    } else if (my_disc.lower_ & 0x40000000UL) {
      my_disc.data_ |= 0x4000000000ULL;
      op_disc.data_ ^= 0x4000000000ULL;
      count += 1;
    }
  }
  if (op_disc.upper_ & 0x200000UL) {
    if (my_disc.upper_ & 0x10000000UL) {
      my_disc.data_ |= 0x20000000000000ULL;
      op_disc.data_ ^= 0x20000000000000ULL;
      count += 1;
    }
  }
  if (op_disc.upper_ & 0x20UL) {
    if (op_disc.lower_ & 0x10000000UL) {
      if (op_disc.lower_ & 0x80000UL) {
        if (op_disc.lower_ & 0x400UL) {
          if (my_disc.lower_ & 0x2UL) {
            my_disc.data_ |= 0x2010080400ULL;
            op_disc.data_ ^= 0x2010080400ULL;
            count += 4;
          }
        } else if (my_disc.lower_ & 0x400UL) {
          my_disc.data_ |= 0x2010080000ULL;
          op_disc.data_ ^= 0x2010080000ULL;
          count += 3;
        }
      } else if (my_disc.lower_ & 0x80000UL) {
        my_disc.data_ |= 0x2010000000ULL;
        op_disc.data_ ^= 0x2010000000ULL;
        count += 2;
      }
    } else if (my_disc.lower_ & 0x10000000UL) {
      my_disc.data_ |= 0x2000000000ULL;
      op_disc.data_ ^= 0x2000000000ULL;
      count += 1;
    }
  }
  return count;
}

static int f_57(bit_matrix& my_disc, bit_matrix& op_disc) {
  int count = 0;
  if (op_disc.upper_ & 0x4000UL) {
    if (op_disc.upper_ & 0x2000UL) {
      if (op_disc.upper_ & 0x1000UL) {
        if (op_disc.upper_ & 0x800UL) {
          if (op_disc.upper_ & 0x400UL) {
            if (op_disc.upper_ & 0x200UL) {
              if (my_disc.upper_ & 0x100UL) {
                my_disc.data_ |= 0x7e0000000000ULL;
                op_disc.data_ ^= 0x7e0000000000ULL;
                count += 6;
              }
            } else if (my_disc.upper_ & 0x200UL) {
              my_disc.data_ |= 0x7c0000000000ULL;
              op_disc.data_ ^= 0x7c0000000000ULL;
              count += 5;
            }
          } else if (my_disc.upper_ & 0x400UL) {
            my_disc.data_ |= 0x780000000000ULL;
            op_disc.data_ ^= 0x780000000000ULL;
            count += 4;
          }
        } else if (my_disc.upper_ & 0x800UL) {
          my_disc.data_ |= 0x700000000000ULL;
          op_disc.data_ ^= 0x700000000000ULL;
          count += 3;
        }
      } else if (my_disc.upper_ & 0x1000UL) {
        my_disc.data_ |= 0x600000000000ULL;
        op_disc.data_ ^= 0x600000000000ULL;
        count += 2;
      }
    } else if (my_disc.upper_ & 0x2000UL) {
      my_disc.data_ |= 0x400000000000ULL;
      op_disc.data_ ^= 0x400000000000ULL;
      count += 1;
    }
  }
  if (op_disc.upper_ & 0x800000UL) {
    if (my_disc.upper_ & 0x80000000UL) {
      my_disc.data_ |= 0x80000000000000ULL;
      op_disc.data_ ^= 0x80000000000000ULL;
      count += 1;
    }
  }
  if (op_disc.upper_ & 0x80UL) {
    if (op_disc.lower_ & 0x80000000UL) {
      if (op_disc.lower_ & 0x800000UL) {
        if (op_disc.lower_ & 0x8000UL) {
          if (my_disc.lower_ & 0x80UL) {
            my_disc.data_ |= 0x8080808000ULL;
            op_disc.data_ ^= 0x8080808000ULL;
            count += 4;
          }
        } else if (my_disc.lower_ & 0x8000UL) {
          my_disc.data_ |= 0x8080800000ULL;
          op_disc.data_ ^= 0x8080800000ULL;
          count += 3;
        }
      } else if (my_disc.lower_ & 0x800000UL) {
        my_disc.data_ |= 0x8080000000ULL;
        op_disc.data_ ^= 0x8080000000ULL;
        count += 2;
      }
    } else if (my_disc.lower_ & 0x80000000UL) {
      my_disc.data_ |= 0x8000000000ULL;
      op_disc.data_ ^= 0x8000000000ULL;
      count += 1;
    }
  }
  if (op_disc.upper_ & 0x400000UL) {
    if (my_disc.upper_ & 0x20000000UL) {
      my_disc.data_ |= 0x40000000000000ULL;
      op_disc.data_ ^= 0x40000000000000ULL;
      count += 1;
    }
  }
  if (op_disc.upper_ & 0x40UL) {
    if (op_disc.lower_ & 0x20000000UL) {
      if (op_disc.lower_ & 0x100000UL) {
        if (op_disc.lower_ & 0x800UL) {
          if (my_disc.lower_ & 0x4UL) {
            my_disc.data_ |= 0x4020100800ULL;
            op_disc.data_ ^= 0x4020100800ULL;
            count += 4;
          }
        } else if (my_disc.lower_ & 0x800UL) {
          my_disc.data_ |= 0x4020100000ULL;
          op_disc.data_ ^= 0x4020100000ULL;
          count += 3;
        }
      } else if (my_disc.lower_ & 0x100000UL) {
        my_disc.data_ |= 0x4020000000ULL;
        op_disc.data_ ^= 0x4020000000ULL;
        count += 2;
      }
    } else if (my_disc.lower_ & 0x20000000UL) {
      my_disc.data_ |= 0x4000000000ULL;
      op_disc.data_ ^= 0x4000000000ULL;
      count += 1;
    }
  }
  return count;
}

static int f_60(bit_matrix& my_disc, bit_matrix& op_disc) {
  int count = 0;
  if (op_disc.upper_ & 0x20000UL) {
    if (op_disc.upper_ & 0x40000UL) {
      if (op_disc.upper_ & 0x80000UL) {
        if (op_disc.upper_ & 0x100000UL) {
          if (op_disc.upper_ & 0x200000UL) {
            if (op_disc.upper_ & 0x400000UL) {
              if (my_disc.upper_ & 0x800000UL) {
                my_disc.data_ |= 0x7e000000000000ULL;
                op_disc.data_ ^= 0x7e000000000000ULL;
                count += 6;
              }
            } else if (my_disc.upper_ & 0x400000UL) {
              my_disc.data_ |= 0x3e000000000000ULL;
              op_disc.data_ ^= 0x3e000000000000ULL;
              count += 5;
            }
          } else if (my_disc.upper_ & 0x200000UL) {
            my_disc.data_ |= 0x1e000000000000ULL;
            op_disc.data_ ^= 0x1e000000000000ULL;
            count += 4;
          }
        } else if (my_disc.upper_ & 0x100000UL) {
          my_disc.data_ |= 0xe000000000000ULL;
          op_disc.data_ ^= 0xe000000000000ULL;
          count += 3;
        }
      } else if (my_disc.upper_ & 0x80000UL) {
        my_disc.data_ |= 0x6000000000000ULL;
        op_disc.data_ ^= 0x6000000000000ULL;
        count += 2;
      }
    } else if (my_disc.upper_ & 0x40000UL) {
      my_disc.data_ |= 0x2000000000000ULL;
      op_disc.data_ ^= 0x2000000000000ULL;
      count += 1;
    }
  }
  if (op_disc.upper_ & 0x100UL) {
    if (op_disc.upper_ & 0x1UL) {
      if (op_disc.lower_ & 0x1000000UL) {
        if (op_disc.lower_ & 0x10000UL) {
          if (op_disc.lower_ & 0x100UL) {
            if (my_disc.lower_ & 0x1UL) {
              my_disc.data_ |= 0x10101010100ULL;
              op_disc.data_ ^= 0x10101010100ULL;
              count += 5;
            }
          } else if (my_disc.lower_ & 0x100UL) {
            my_disc.data_ |= 0x10101010000ULL;
            op_disc.data_ ^= 0x10101010000ULL;
            count += 4;
          }
        } else if (my_disc.lower_ & 0x10000UL) {
          my_disc.data_ |= 0x10101000000ULL;
          op_disc.data_ ^= 0x10101000000ULL;
          count += 3;
        }
      } else if (my_disc.lower_ & 0x1000000UL) {
        my_disc.data_ |= 0x10100000000ULL;
        op_disc.data_ ^= 0x10100000000ULL;
        count += 2;
      }
    } else if (my_disc.upper_ & 0x1UL) {
      my_disc.data_ |= 0x10000000000ULL;
      op_disc.data_ ^= 0x10000000000ULL;
      count += 1;
    }
  }
  if (op_disc.upper_ & 0x200UL) {
    if (op_disc.upper_ & 0x4UL) {
      if (op_disc.lower_ & 0x8000000UL) {
        if (op_disc.lower_ & 0x100000UL) {
          if (op_disc.lower_ & 0x2000UL) {
            if (my_disc.lower_ & 0x40UL) {
              my_disc.data_ |= 0x20408102000ULL;
              op_disc.data_ ^= 0x20408102000ULL;
              count += 5;
            }
          } else if (my_disc.lower_ & 0x2000UL) {
            my_disc.data_ |= 0x20408100000ULL;
            op_disc.data_ ^= 0x20408100000ULL;
            count += 4;
          }
        } else if (my_disc.lower_ & 0x100000UL) {
          my_disc.data_ |= 0x20408000000ULL;
          op_disc.data_ ^= 0x20408000000ULL;
          count += 3;
        }
      } else if (my_disc.lower_ & 0x8000000UL) {
        my_disc.data_ |= 0x20400000000ULL;
        op_disc.data_ ^= 0x20400000000ULL;
        count += 2;
      }
    } else if (my_disc.upper_ & 0x4UL) {
      my_disc.data_ |= 0x20000000000ULL;
      op_disc.data_ ^= 0x20000000000ULL;
      count += 1;
    }
  }
  return count;
}

static int f_61(bit_matrix& my_disc, bit_matrix& op_disc) {
  int count = 0;
  if (op_disc.upper_ & 0x40000UL) {
    if (op_disc.upper_ & 0x80000UL) {
      if (op_disc.upper_ & 0x100000UL) {
        if (op_disc.upper_ & 0x200000UL) {
          if (op_disc.upper_ & 0x400000UL) {
            if (my_disc.upper_ & 0x800000UL) {
              my_disc.data_ |= 0x7c000000000000ULL;
              op_disc.data_ ^= 0x7c000000000000ULL;
              count += 5;
            }
          } else if (my_disc.upper_ & 0x400000UL) {
            my_disc.data_ |= 0x3c000000000000ULL;
            op_disc.data_ ^= 0x3c000000000000ULL;
            count += 4;
          }
        } else if (my_disc.upper_ & 0x200000UL) {
          my_disc.data_ |= 0x1c000000000000ULL;
          op_disc.data_ ^= 0x1c000000000000ULL;
          count += 3;
        }
      } else if (my_disc.upper_ & 0x100000UL) {
        my_disc.data_ |= 0xc000000000000ULL;
        op_disc.data_ ^= 0xc000000000000ULL;
        count += 2;
      }
    } else if (my_disc.upper_ & 0x80000UL) {
      my_disc.data_ |= 0x4000000000000ULL;
      op_disc.data_ ^= 0x4000000000000ULL;
      count += 1;
    }
  }
  if (op_disc.upper_ & 0x200UL) {
    if (op_disc.upper_ & 0x2UL) {
      if (op_disc.lower_ & 0x2000000UL) {
        if (op_disc.lower_ & 0x20000UL) {
          if (op_disc.lower_ & 0x200UL) {
            if (my_disc.lower_ & 0x2UL) {
              my_disc.data_ |= 0x20202020200ULL;
              op_disc.data_ ^= 0x20202020200ULL;
              count += 5;
            }
          } else if (my_disc.lower_ & 0x200UL) {
            my_disc.data_ |= 0x20202020000ULL;
            op_disc.data_ ^= 0x20202020000ULL;
            count += 4;
          }
        } else if (my_disc.lower_ & 0x20000UL) {
          my_disc.data_ |= 0x20202000000ULL;
          op_disc.data_ ^= 0x20202000000ULL;
          count += 3;
        }
      } else if (my_disc.lower_ & 0x2000000UL) {
        my_disc.data_ |= 0x20200000000ULL;
        op_disc.data_ ^= 0x20200000000ULL;
        count += 2;
      }
    } else if (my_disc.upper_ & 0x2UL) {
      my_disc.data_ |= 0x20000000000ULL;
      op_disc.data_ ^= 0x20000000000ULL;
      count += 1;
    }
  }
  if (op_disc.upper_ & 0x400UL) {
    if (op_disc.upper_ & 0x8UL) {
      if (op_disc.lower_ & 0x10000000UL) {
        if (op_disc.lower_ & 0x200000UL) {
          if (op_disc.lower_ & 0x4000UL) {
            if (my_disc.lower_ & 0x80UL) {
              my_disc.data_ |= 0x40810204000ULL;
              op_disc.data_ ^= 0x40810204000ULL;
              count += 5;
            }
          } else if (my_disc.lower_ & 0x4000UL) {
            my_disc.data_ |= 0x40810200000ULL;
            op_disc.data_ ^= 0x40810200000ULL;
            count += 4;
          }
        } else if (my_disc.lower_ & 0x200000UL) {
          my_disc.data_ |= 0x40810000000ULL;
          op_disc.data_ ^= 0x40810000000ULL;
          count += 3;
        }
      } else if (my_disc.lower_ & 0x10000000UL) {
        my_disc.data_ |= 0x40800000000ULL;
        op_disc.data_ ^= 0x40800000000ULL;
        count += 2;
      }
    } else if (my_disc.upper_ & 0x8UL) {
      my_disc.data_ |= 0x40000000000ULL;
      op_disc.data_ ^= 0x40000000000ULL;
      count += 1;
    }
  }
  return count;
}

static int f_62(bit_matrix& my_disc, bit_matrix& op_disc) {
  int count = 0;
  if (op_disc.upper_ & 0x80000UL) {
    if (op_disc.upper_ & 0x100000UL) {
      if (op_disc.upper_ & 0x200000UL) {
        if (op_disc.upper_ & 0x400000UL) {
          if (my_disc.upper_ & 0x800000UL) {
            my_disc.data_ |= 0x78000000000000ULL;
            op_disc.data_ ^= 0x78000000000000ULL;
            count += 4;
          }
        } else if (my_disc.upper_ & 0x400000UL) {
          my_disc.data_ |= 0x38000000000000ULL;
          op_disc.data_ ^= 0x38000000000000ULL;
          count += 3;
        }
      } else if (my_disc.upper_ & 0x200000UL) {
        my_disc.data_ |= 0x18000000000000ULL;
        op_disc.data_ ^= 0x18000000000000ULL;
        count += 2;
      }
    } else if (my_disc.upper_ & 0x100000UL) {
      my_disc.data_ |= 0x8000000000000ULL;
      op_disc.data_ ^= 0x8000000000000ULL;
      count += 1;
    }
  }
  if (op_disc.upper_ & 0x20000UL) {
    if (my_disc.upper_ & 0x10000UL) {
      my_disc.data_ |= 0x2000000000000ULL;
      op_disc.data_ ^= 0x2000000000000ULL;
      count += 1;
    }
  }
  if (op_disc.upper_ & 0x400UL) {
    if (op_disc.upper_ & 0x4UL) {
      if (op_disc.lower_ & 0x4000000UL) {
        if (op_disc.lower_ & 0x40000UL) {
          if (op_disc.lower_ & 0x400UL) {
            if (my_disc.lower_ & 0x4UL) {
              my_disc.data_ |= 0x40404040400ULL;
              op_disc.data_ ^= 0x40404040400ULL;
              count += 5;
            }
          } else if (my_disc.lower_ & 0x400UL) {
            my_disc.data_ |= 0x40404040000ULL;
            op_disc.data_ ^= 0x40404040000ULL;
            count += 4;
          }
        } else if (my_disc.lower_ & 0x40000UL) {
          my_disc.data_ |= 0x40404000000ULL;
          op_disc.data_ ^= 0x40404000000ULL;
          count += 3;
        }
      } else if (my_disc.lower_ & 0x4000000UL) {
        my_disc.data_ |= 0x40400000000ULL;
        op_disc.data_ ^= 0x40400000000ULL;
        count += 2;
      }
    } else if (my_disc.upper_ & 0x4UL) {
      my_disc.data_ |= 0x40000000000ULL;
      op_disc.data_ ^= 0x40000000000ULL;
      count += 1;
    }
  }
  if (op_disc.upper_ & 0x800UL) {
    if (op_disc.upper_ & 0x10UL) {
      if (op_disc.lower_ & 0x20000000UL) {
        if (op_disc.lower_ & 0x400000UL) {
          if (my_disc.lower_ & 0x8000UL) {
            my_disc.data_ |= 0x81020400000ULL;
            op_disc.data_ ^= 0x81020400000ULL;
            count += 4;
          }
        } else if (my_disc.lower_ & 0x400000UL) {
          my_disc.data_ |= 0x81020000000ULL;
          op_disc.data_ ^= 0x81020000000ULL;
          count += 3;
        }
      } else if (my_disc.lower_ & 0x20000000UL) {
        my_disc.data_ |= 0x81000000000ULL;
        op_disc.data_ ^= 0x81000000000ULL;
        count += 2;
      }
    } else if (my_disc.upper_ & 0x10UL) {
      my_disc.data_ |= 0x80000000000ULL;
      op_disc.data_ ^= 0x80000000000ULL;
      count += 1;
    }
  }
  if (op_disc.upper_ & 0x200UL) {
    if (my_disc.upper_ & 0x1UL) {
      my_disc.data_ |= 0x20000000000ULL;
      op_disc.data_ ^= 0x20000000000ULL;
      count += 1;
    }
  }
  return count;
}

static int f_63(bit_matrix& my_disc, bit_matrix& op_disc) {
  int count = 0;
  if (op_disc.upper_ & 0x100000UL) {
    if (op_disc.upper_ & 0x200000UL) {
      if (op_disc.upper_ & 0x400000UL) {
        if (my_disc.upper_ & 0x800000UL) {
          my_disc.data_ |= 0x70000000000000ULL;
          op_disc.data_ ^= 0x70000000000000ULL;
          count += 3;
        }
      } else if (my_disc.upper_ & 0x400000UL) {
        my_disc.data_ |= 0x30000000000000ULL;
        op_disc.data_ ^= 0x30000000000000ULL;
        count += 2;
      }
    } else if (my_disc.upper_ & 0x200000UL) {
      my_disc.data_ |= 0x10000000000000ULL;
      op_disc.data_ ^= 0x10000000000000ULL;
      count += 1;
    }
  }
  if (op_disc.upper_ & 0x40000UL) {
    if (op_disc.upper_ & 0x20000UL) {
      if (my_disc.upper_ & 0x10000UL) {
        my_disc.data_ |= 0x6000000000000ULL;
        op_disc.data_ ^= 0x6000000000000ULL;
        count += 2;
      }
    } else if (my_disc.upper_ & 0x20000UL) {
      my_disc.data_ |= 0x4000000000000ULL;
      op_disc.data_ ^= 0x4000000000000ULL;
      count += 1;
    }
  }
  if (op_disc.upper_ & 0x800UL) {
    if (op_disc.upper_ & 0x8UL) {
      if (op_disc.lower_ & 0x8000000UL) {
        if (op_disc.lower_ & 0x80000UL) {
          if (op_disc.lower_ & 0x800UL) {
            if (my_disc.lower_ & 0x8UL) {
              my_disc.data_ |= 0x80808080800ULL;
              op_disc.data_ ^= 0x80808080800ULL;
              count += 5;
            }
          } else if (my_disc.lower_ & 0x800UL) {
            my_disc.data_ |= 0x80808080000ULL;
            op_disc.data_ ^= 0x80808080000ULL;
            count += 4;
          }
        } else if (my_disc.lower_ & 0x80000UL) {
          my_disc.data_ |= 0x80808000000ULL;
          op_disc.data_ ^= 0x80808000000ULL;
          count += 3;
        }
      } else if (my_disc.lower_ & 0x8000000UL) {
        my_disc.data_ |= 0x80800000000ULL;
        op_disc.data_ ^= 0x80800000000ULL;
        count += 2;
      }
    } else if (my_disc.upper_ & 0x8UL) {
      my_disc.data_ |= 0x80000000000ULL;
      op_disc.data_ ^= 0x80000000000ULL;
      count += 1;
    }
  }
  if (op_disc.upper_ & 0x1000UL) {
    if (op_disc.upper_ & 0x20UL) {
      if (op_disc.lower_ & 0x40000000UL) {
        if (my_disc.lower_ & 0x800000UL) {
          my_disc.data_ |= 0x102040000000ULL;
          op_disc.data_ ^= 0x102040000000ULL;
          count += 3;
        }
      } else if (my_disc.lower_ & 0x40000000UL) {
        my_disc.data_ |= 0x102000000000ULL;
        op_disc.data_ ^= 0x102000000000ULL;
        count += 2;
      }
    } else if (my_disc.upper_ & 0x20UL) {
      my_disc.data_ |= 0x100000000000ULL;
      op_disc.data_ ^= 0x100000000000ULL;
      count += 1;
    }
  }
  if (op_disc.upper_ & 0x400UL) {
    if (op_disc.upper_ & 0x2UL) {
      if (my_disc.lower_ & 0x1000000UL) {
        my_disc.data_ |= 0x40200000000ULL;
        op_disc.data_ ^= 0x40200000000ULL;
        count += 2;
      }
    } else if (my_disc.upper_ & 0x2UL) {
      my_disc.data_ |= 0x40000000000ULL;
      op_disc.data_ ^= 0x40000000000ULL;
      count += 1;
    }
  }
  return count;
}

static int f_64(bit_matrix& my_disc, bit_matrix& op_disc) {
  int count = 0;
  if (op_disc.upper_ & 0x200000UL) {
    if (op_disc.upper_ & 0x400000UL) {
      if (my_disc.upper_ & 0x800000UL) {
        my_disc.data_ |= 0x60000000000000ULL;
        op_disc.data_ ^= 0x60000000000000ULL;
        count += 2;
      }
    } else if (my_disc.upper_ & 0x400000UL) {
      my_disc.data_ |= 0x20000000000000ULL;
      op_disc.data_ ^= 0x20000000000000ULL;
      count += 1;
    }
  }
  if (op_disc.upper_ & 0x80000UL) {
    if (op_disc.upper_ & 0x40000UL) {
      if (op_disc.upper_ & 0x20000UL) {
        if (my_disc.upper_ & 0x10000UL) {
          my_disc.data_ |= 0xe000000000000ULL;
          op_disc.data_ ^= 0xe000000000000ULL;
          count += 3;
        }
      } else if (my_disc.upper_ & 0x20000UL) {
        my_disc.data_ |= 0xc000000000000ULL;
        op_disc.data_ ^= 0xc000000000000ULL;
        count += 2;
      }
    } else if (my_disc.upper_ & 0x40000UL) {
      my_disc.data_ |= 0x8000000000000ULL;
      op_disc.data_ ^= 0x8000000000000ULL;
      count += 1;
    }
  }
  if (op_disc.upper_ & 0x1000UL) {
    if (op_disc.upper_ & 0x10UL) {
      if (op_disc.lower_ & 0x10000000UL) {
        if (op_disc.lower_ & 0x100000UL) {
          if (op_disc.lower_ & 0x1000UL) {
            if (my_disc.lower_ & 0x10UL) {
              my_disc.data_ |= 0x101010101000ULL;
              op_disc.data_ ^= 0x101010101000ULL;
              count += 5;
            }
          } else if (my_disc.lower_ & 0x1000UL) {
            my_disc.data_ |= 0x101010100000ULL;
            op_disc.data_ ^= 0x101010100000ULL;
            count += 4;
          }
        } else if (my_disc.lower_ & 0x100000UL) {
          my_disc.data_ |= 0x101010000000ULL;
          op_disc.data_ ^= 0x101010000000ULL;
          count += 3;
        }
      } else if (my_disc.lower_ & 0x10000000UL) {
        my_disc.data_ |= 0x101000000000ULL;
        op_disc.data_ ^= 0x101000000000ULL;
        count += 2;
      }
    } else if (my_disc.upper_ & 0x10UL) {
      my_disc.data_ |= 0x100000000000ULL;
      op_disc.data_ ^= 0x100000000000ULL;
      count += 1;
    }
  }
  if (op_disc.upper_ & 0x2000UL) {
    if (op_disc.upper_ & 0x40UL) {
      if (my_disc.lower_ & 0x80000000UL) {
        my_disc.data_ |= 0x204000000000ULL;
        op_disc.data_ ^= 0x204000000000ULL;
        count += 2;
      }
    } else if (my_disc.upper_ & 0x40UL) {
      my_disc.data_ |= 0x200000000000ULL;
      op_disc.data_ ^= 0x200000000000ULL;
      count += 1;
    }
  }
  if (op_disc.upper_ & 0x800UL) {
    if (op_disc.upper_ & 0x4UL) {
      if (op_disc.lower_ & 0x2000000UL) {
        if (my_disc.lower_ & 0x10000UL) {
          my_disc.data_ |= 0x80402000000ULL;
          op_disc.data_ ^= 0x80402000000ULL;
          count += 3;
        }
      } else if (my_disc.lower_ & 0x2000000UL) {
        my_disc.data_ |= 0x80400000000ULL;
        op_disc.data_ ^= 0x80400000000ULL;
        count += 2;
      }
    } else if (my_disc.upper_ & 0x4UL) {
      my_disc.data_ |= 0x80000000000ULL;
      op_disc.data_ ^= 0x80000000000ULL;
      count += 1;
    }
  }
  return count;
}

static int f_65(bit_matrix& my_disc, bit_matrix& op_disc) {
  int count = 0;
  if (op_disc.upper_ & 0x400000UL) {
    if (my_disc.upper_ & 0x800000UL) {
      my_disc.data_ |= 0x40000000000000ULL;
      op_disc.data_ ^= 0x40000000000000ULL;
      count += 1;
    }
  }
  if (op_disc.upper_ & 0x100000UL) {
    if (op_disc.upper_ & 0x80000UL) {
      if (op_disc.upper_ & 0x40000UL) {
        if (op_disc.upper_ & 0x20000UL) {
          if (my_disc.upper_ & 0x10000UL) {
            my_disc.data_ |= 0x1e000000000000ULL;
            op_disc.data_ ^= 0x1e000000000000ULL;
            count += 4;
          }
        } else if (my_disc.upper_ & 0x20000UL) {
          my_disc.data_ |= 0x1c000000000000ULL;
          op_disc.data_ ^= 0x1c000000000000ULL;
          count += 3;
        }
      } else if (my_disc.upper_ & 0x40000UL) {
        my_disc.data_ |= 0x18000000000000ULL;
        op_disc.data_ ^= 0x18000000000000ULL;
        count += 2;
      }
    } else if (my_disc.upper_ & 0x80000UL) {
      my_disc.data_ |= 0x10000000000000ULL;
      op_disc.data_ ^= 0x10000000000000ULL;
      count += 1;
    }
  }
  if (op_disc.upper_ & 0x2000UL) {
    if (op_disc.upper_ & 0x20UL) {
      if (op_disc.lower_ & 0x20000000UL) {
        if (op_disc.lower_ & 0x200000UL) {
          if (op_disc.lower_ & 0x2000UL) {
            if (my_disc.lower_ & 0x20UL) {
              my_disc.data_ |= 0x202020202000ULL;
              op_disc.data_ ^= 0x202020202000ULL;
              count += 5;
            }
          } else if (my_disc.lower_ & 0x2000UL) {
            my_disc.data_ |= 0x202020200000ULL;
            op_disc.data_ ^= 0x202020200000ULL;
            count += 4;
          }
        } else if (my_disc.lower_ & 0x200000UL) {
          my_disc.data_ |= 0x202020000000ULL;
          op_disc.data_ ^= 0x202020000000ULL;
          count += 3;
        }
      } else if (my_disc.lower_ & 0x20000000UL) {
        my_disc.data_ |= 0x202000000000ULL;
        op_disc.data_ ^= 0x202000000000ULL;
        count += 2;
      }
    } else if (my_disc.upper_ & 0x20UL) {
      my_disc.data_ |= 0x200000000000ULL;
      op_disc.data_ ^= 0x200000000000ULL;
      count += 1;
    }
  }
  if (op_disc.upper_ & 0x4000UL) {
    if (my_disc.upper_ & 0x80UL) {
      my_disc.data_ |= 0x400000000000ULL;
      op_disc.data_ ^= 0x400000000000ULL;
      count += 1;
    }
  }
  if (op_disc.upper_ & 0x1000UL) {
    if (op_disc.upper_ & 0x8UL) {
      if (op_disc.lower_ & 0x4000000UL) {
        if (op_disc.lower_ & 0x20000UL) {
          if (my_disc.lower_ & 0x100UL) {
            my_disc.data_ |= 0x100804020000ULL;
            op_disc.data_ ^= 0x100804020000ULL;
            count += 4;
          }
        } else if (my_disc.lower_ & 0x20000UL) {
          my_disc.data_ |= 0x100804000000ULL;
          op_disc.data_ ^= 0x100804000000ULL;
          count += 3;
        }
      } else if (my_disc.lower_ & 0x4000000UL) {
        my_disc.data_ |= 0x100800000000ULL;
        op_disc.data_ ^= 0x100800000000ULL;
        count += 2;
      }
    } else if (my_disc.upper_ & 0x8UL) {
      my_disc.data_ |= 0x100000000000ULL;
      op_disc.data_ ^= 0x100000000000ULL;
      count += 1;
    }
  }
  return count;
}

static int f_66(bit_matrix& my_disc, bit_matrix& op_disc) {
  int count = 0;
  if (op_disc.upper_ & 0x200000UL) {
    if (op_disc.upper_ & 0x100000UL) {
      if (op_disc.upper_ & 0x80000UL) {
        if (op_disc.upper_ & 0x40000UL) {
          if (op_disc.upper_ & 0x20000UL) {
            if (my_disc.upper_ & 0x10000UL) {
              my_disc.data_ |= 0x3e000000000000ULL;
              op_disc.data_ ^= 0x3e000000000000ULL;
              count += 5;
            }
          } else if (my_disc.upper_ & 0x20000UL) {
            my_disc.data_ |= 0x3c000000000000ULL;
            op_disc.data_ ^= 0x3c000000000000ULL;
            count += 4;
          }
        } else if (my_disc.upper_ & 0x40000UL) {
          my_disc.data_ |= 0x38000000000000ULL;
          op_disc.data_ ^= 0x38000000000000ULL;
          count += 3;
        }
      } else if (my_disc.upper_ & 0x80000UL) {
        my_disc.data_ |= 0x30000000000000ULL;
        op_disc.data_ ^= 0x30000000000000ULL;
        count += 2;
      }
    } else if (my_disc.upper_ & 0x100000UL) {
      my_disc.data_ |= 0x20000000000000ULL;
      op_disc.data_ ^= 0x20000000000000ULL;
      count += 1;
    }
  }
  if (op_disc.upper_ & 0x4000UL) {
    if (op_disc.upper_ & 0x40UL) {
      if (op_disc.lower_ & 0x40000000UL) {
        if (op_disc.lower_ & 0x400000UL) {
          if (op_disc.lower_ & 0x4000UL) {
            if (my_disc.lower_ & 0x40UL) {
              my_disc.data_ |= 0x404040404000ULL;
              op_disc.data_ ^= 0x404040404000ULL;
              count += 5;
            }
          } else if (my_disc.lower_ & 0x4000UL) {
            my_disc.data_ |= 0x404040400000ULL;
            op_disc.data_ ^= 0x404040400000ULL;
            count += 4;
          }
        } else if (my_disc.lower_ & 0x400000UL) {
          my_disc.data_ |= 0x404040000000ULL;
          op_disc.data_ ^= 0x404040000000ULL;
          count += 3;
        }
      } else if (my_disc.lower_ & 0x40000000UL) {
        my_disc.data_ |= 0x404000000000ULL;
        op_disc.data_ ^= 0x404000000000ULL;
        count += 2;
      }
    } else if (my_disc.upper_ & 0x40UL) {
      my_disc.data_ |= 0x400000000000ULL;
      op_disc.data_ ^= 0x400000000000ULL;
      count += 1;
    }
  }
  if (op_disc.upper_ & 0x2000UL) {
    if (op_disc.upper_ & 0x10UL) {
      if (op_disc.lower_ & 0x8000000UL) {
        if (op_disc.lower_ & 0x40000UL) {
          if (op_disc.lower_ & 0x200UL) {
            if (my_disc.lower_ & 0x1UL) {
              my_disc.data_ |= 0x201008040200ULL;
              op_disc.data_ ^= 0x201008040200ULL;
              count += 5;
            }
          } else if (my_disc.lower_ & 0x200UL) {
            my_disc.data_ |= 0x201008040000ULL;
            op_disc.data_ ^= 0x201008040000ULL;
            count += 4;
          }
        } else if (my_disc.lower_ & 0x40000UL) {
          my_disc.data_ |= 0x201008000000ULL;
          op_disc.data_ ^= 0x201008000000ULL;
          count += 3;
        }
      } else if (my_disc.lower_ & 0x8000000UL) {
        my_disc.data_ |= 0x201000000000ULL;
        op_disc.data_ ^= 0x201000000000ULL;
        count += 2;
      }
    } else if (my_disc.upper_ & 0x10UL) {
      my_disc.data_ |= 0x200000000000ULL;
      op_disc.data_ ^= 0x200000000000ULL;
      count += 1;
    }
  }
  return count;
}

static int f_67(bit_matrix& my_disc, bit_matrix& op_disc) {
  int count = 0;
  if (op_disc.upper_ & 0x400000UL) {
    if (op_disc.upper_ & 0x200000UL) {
      if (op_disc.upper_ & 0x100000UL) {
        if (op_disc.upper_ & 0x80000UL) {
          if (op_disc.upper_ & 0x40000UL) {
            if (op_disc.upper_ & 0x20000UL) {
              if (my_disc.upper_ & 0x10000UL) {
                my_disc.data_ |= 0x7e000000000000ULL;
                op_disc.data_ ^= 0x7e000000000000ULL;
                count += 6;
              }
            } else if (my_disc.upper_ & 0x20000UL) {
              my_disc.data_ |= 0x7c000000000000ULL;
              op_disc.data_ ^= 0x7c000000000000ULL;
              count += 5;
            }
          } else if (my_disc.upper_ & 0x40000UL) {
            my_disc.data_ |= 0x78000000000000ULL;
            op_disc.data_ ^= 0x78000000000000ULL;
            count += 4;
          }
        } else if (my_disc.upper_ & 0x80000UL) {
          my_disc.data_ |= 0x70000000000000ULL;
          op_disc.data_ ^= 0x70000000000000ULL;
          count += 3;
        }
      } else if (my_disc.upper_ & 0x100000UL) {
        my_disc.data_ |= 0x60000000000000ULL;
        op_disc.data_ ^= 0x60000000000000ULL;
        count += 2;
      }
    } else if (my_disc.upper_ & 0x200000UL) {
      my_disc.data_ |= 0x40000000000000ULL;
      op_disc.data_ ^= 0x40000000000000ULL;
      count += 1;
    }
  }
  if (op_disc.upper_ & 0x8000UL) {
    if (op_disc.upper_ & 0x80UL) {
      if (op_disc.lower_ & 0x80000000UL) {
        if (op_disc.lower_ & 0x800000UL) {
          if (op_disc.lower_ & 0x8000UL) {
            if (my_disc.lower_ & 0x80UL) {
              my_disc.data_ |= 0x808080808000ULL;
              op_disc.data_ ^= 0x808080808000ULL;
              count += 5;
            }
          } else if (my_disc.lower_ & 0x8000UL) {
            my_disc.data_ |= 0x808080800000ULL;
            op_disc.data_ ^= 0x808080800000ULL;
            count += 4;
          }
        } else if (my_disc.lower_ & 0x800000UL) {
          my_disc.data_ |= 0x808080000000ULL;
          op_disc.data_ ^= 0x808080000000ULL;
          count += 3;
        }
      } else if (my_disc.lower_ & 0x80000000UL) {
        my_disc.data_ |= 0x808000000000ULL;
        op_disc.data_ ^= 0x808000000000ULL;
        count += 2;
      }
    } else if (my_disc.upper_ & 0x80UL) {
      my_disc.data_ |= 0x800000000000ULL;
      op_disc.data_ ^= 0x800000000000ULL;
      count += 1;
    }
  }
  if (op_disc.upper_ & 0x4000UL) {
    if (op_disc.upper_ & 0x20UL) {
      if (op_disc.lower_ & 0x10000000UL) {
        if (op_disc.lower_ & 0x80000UL) {
          if (op_disc.lower_ & 0x400UL) {
            if (my_disc.lower_ & 0x2UL) {
              my_disc.data_ |= 0x402010080400ULL;
              op_disc.data_ ^= 0x402010080400ULL;
              count += 5;
            }
          } else if (my_disc.lower_ & 0x400UL) {
            my_disc.data_ |= 0x402010080000ULL;
            op_disc.data_ ^= 0x402010080000ULL;
            count += 4;
          }
        } else if (my_disc.lower_ & 0x80000UL) {
          my_disc.data_ |= 0x402010000000ULL;
          op_disc.data_ ^= 0x402010000000ULL;
          count += 3;
        }
      } else if (my_disc.lower_ & 0x10000000UL) {
        my_disc.data_ |= 0x402000000000ULL;
        op_disc.data_ ^= 0x402000000000ULL;
        count += 2;
      }
    } else if (my_disc.upper_ & 0x20UL) {
      my_disc.data_ |= 0x400000000000ULL;
      op_disc.data_ ^= 0x400000000000ULL;
      count += 1;
    }
  }
  return count;
}

static int f_70(bit_matrix& my_disc, bit_matrix& op_disc) {
  int count = 0;
  if (op_disc.upper_ & 0x2000000UL) {
    if (op_disc.upper_ & 0x4000000UL) {
      if (op_disc.upper_ & 0x8000000UL) {
        if (op_disc.upper_ & 0x10000000UL) {
          if (op_disc.upper_ & 0x20000000UL) {
            if (op_disc.upper_ & 0x40000000UL) {
              if (my_disc.upper_ & 0x80000000UL) {
                my_disc.data_ |= 0x7e00000000000000ULL;
                op_disc.data_ ^= 0x7e00000000000000ULL;
                count += 6;
              }
            } else if (my_disc.upper_ & 0x40000000UL) {
              my_disc.data_ |= 0x3e00000000000000ULL;
              op_disc.data_ ^= 0x3e00000000000000ULL;
              count += 5;
            }
          } else if (my_disc.upper_ & 0x20000000UL) {
            my_disc.data_ |= 0x1e00000000000000ULL;
            op_disc.data_ ^= 0x1e00000000000000ULL;
            count += 4;
          }
        } else if (my_disc.upper_ & 0x10000000UL) {
          my_disc.data_ |= 0xe00000000000000ULL;
          op_disc.data_ ^= 0xe00000000000000ULL;
          count += 3;
        }
      } else if (my_disc.upper_ & 0x8000000UL) {
        my_disc.data_ |= 0x600000000000000ULL;
        op_disc.data_ ^= 0x600000000000000ULL;
        count += 2;
      }
    } else if (my_disc.upper_ & 0x4000000UL) {
      my_disc.data_ |= 0x200000000000000ULL;
      op_disc.data_ ^= 0x200000000000000ULL;
      count += 1;
    }
  }
  if (op_disc.upper_ & 0x10000UL) {
    if (op_disc.upper_ & 0x100UL) {
      if (op_disc.upper_ & 0x1UL) {
        if (op_disc.lower_ & 0x1000000UL) {
          if (op_disc.lower_ & 0x10000UL) {
            if (op_disc.lower_ & 0x100UL) {
              if (my_disc.lower_ & 0x1UL) {
                my_disc.data_ |= 0x1010101010100ULL;
                op_disc.data_ ^= 0x1010101010100ULL;
                count += 6;
              }
            } else if (my_disc.lower_ & 0x100UL) {
              my_disc.data_ |= 0x1010101010000ULL;
              op_disc.data_ ^= 0x1010101010000ULL;
              count += 5;
            }
          } else if (my_disc.lower_ & 0x10000UL) {
            my_disc.data_ |= 0x1010101000000ULL;
            op_disc.data_ ^= 0x1010101000000ULL;
            count += 4;
          }
        } else if (my_disc.lower_ & 0x1000000UL) {
          my_disc.data_ |= 0x1010100000000ULL;
          op_disc.data_ ^= 0x1010100000000ULL;
          count += 3;
        }
      } else if (my_disc.upper_ & 0x1UL) {
        my_disc.data_ |= 0x1010000000000ULL;
        op_disc.data_ ^= 0x1010000000000ULL;
        count += 2;
      }
    } else if (my_disc.upper_ & 0x100UL) {
      my_disc.data_ |= 0x1000000000000ULL;
      op_disc.data_ ^= 0x1000000000000ULL;
      count += 1;
    }
  }
  if (op_disc.upper_ & 0x20000UL) {
    if (op_disc.upper_ & 0x400UL) {
      if (op_disc.upper_ & 0x8UL) {
        if (op_disc.lower_ & 0x10000000UL) {
          if (op_disc.lower_ & 0x200000UL) {
            if (op_disc.lower_ & 0x4000UL) {
              if (my_disc.lower_ & 0x80UL) {
                my_disc.data_ |= 0x2040810204000ULL;
                op_disc.data_ ^= 0x2040810204000ULL;
                count += 6;
              }
            } else if (my_disc.lower_ & 0x4000UL) {
              my_disc.data_ |= 0x2040810200000ULL;
              op_disc.data_ ^= 0x2040810200000ULL;
              count += 5;
            }
          } else if (my_disc.lower_ & 0x200000UL) {
            my_disc.data_ |= 0x2040810000000ULL;
            op_disc.data_ ^= 0x2040810000000ULL;
            count += 4;
          }
        } else if (my_disc.lower_ & 0x10000000UL) {
          my_disc.data_ |= 0x2040800000000ULL;
          op_disc.data_ ^= 0x2040800000000ULL;
          count += 3;
        }
      } else if (my_disc.upper_ & 0x8UL) {
        my_disc.data_ |= 0x2040000000000ULL;
        op_disc.data_ ^= 0x2040000000000ULL;
        count += 2;
      }
    } else if (my_disc.upper_ & 0x400UL) {
      my_disc.data_ |= 0x2000000000000ULL;
      op_disc.data_ ^= 0x2000000000000ULL;
      count += 1;
    }
  }
  return count;
}

static int f_71(bit_matrix& my_disc, bit_matrix& op_disc) {
  int count = 0;
  if (op_disc.upper_ & 0x4000000UL) {
    if (op_disc.upper_ & 0x8000000UL) {
      if (op_disc.upper_ & 0x10000000UL) {
        if (op_disc.upper_ & 0x20000000UL) {
          if (op_disc.upper_ & 0x40000000UL) {
            if (my_disc.upper_ & 0x80000000UL) {
              my_disc.data_ |= 0x7c00000000000000ULL;
              op_disc.data_ ^= 0x7c00000000000000ULL;
              count += 5;
            }
          } else if (my_disc.upper_ & 0x40000000UL) {
            my_disc.data_ |= 0x3c00000000000000ULL;
            op_disc.data_ ^= 0x3c00000000000000ULL;
            count += 4;
          }
        } else if (my_disc.upper_ & 0x20000000UL) {
          my_disc.data_ |= 0x1c00000000000000ULL;
          op_disc.data_ ^= 0x1c00000000000000ULL;
          count += 3;
        }
      } else if (my_disc.upper_ & 0x10000000UL) {
        my_disc.data_ |= 0xc00000000000000ULL;
        op_disc.data_ ^= 0xc00000000000000ULL;
        count += 2;
      }
    } else if (my_disc.upper_ & 0x8000000UL) {
      my_disc.data_ |= 0x400000000000000ULL;
      op_disc.data_ ^= 0x400000000000000ULL;
      count += 1;
    }
  }
  if (op_disc.upper_ & 0x20000UL) {
    if (op_disc.upper_ & 0x200UL) {
      if (op_disc.upper_ & 0x2UL) {
        if (op_disc.lower_ & 0x2000000UL) {
          if (op_disc.lower_ & 0x20000UL) {
            if (op_disc.lower_ & 0x200UL) {
              if (my_disc.lower_ & 0x2UL) {
                my_disc.data_ |= 0x2020202020200ULL;
                op_disc.data_ ^= 0x2020202020200ULL;
                count += 6;
              }
            } else if (my_disc.lower_ & 0x200UL) {
              my_disc.data_ |= 0x2020202020000ULL;
              op_disc.data_ ^= 0x2020202020000ULL;
              count += 5;
            }
          } else if (my_disc.lower_ & 0x20000UL) {
            my_disc.data_ |= 0x2020202000000ULL;
            op_disc.data_ ^= 0x2020202000000ULL;
            count += 4;
          }
        } else if (my_disc.lower_ & 0x2000000UL) {
          my_disc.data_ |= 0x2020200000000ULL;
          op_disc.data_ ^= 0x2020200000000ULL;
          count += 3;
        }
      } else if (my_disc.upper_ & 0x2UL) {
        my_disc.data_ |= 0x2020000000000ULL;
        op_disc.data_ ^= 0x2020000000000ULL;
        count += 2;
      }
    } else if (my_disc.upper_ & 0x200UL) {
      my_disc.data_ |= 0x2000000000000ULL;
      op_disc.data_ ^= 0x2000000000000ULL;
      count += 1;
    }
  }
  if (op_disc.upper_ & 0x40000UL) {
    if (op_disc.upper_ & 0x800UL) {
      if (op_disc.upper_ & 0x10UL) {
        if (op_disc.lower_ & 0x20000000UL) {
          if (op_disc.lower_ & 0x400000UL) {
            if (my_disc.lower_ & 0x8000UL) {
              my_disc.data_ |= 0x4081020400000ULL;
              op_disc.data_ ^= 0x4081020400000ULL;
              count += 5;
            }
          } else if (my_disc.lower_ & 0x400000UL) {
            my_disc.data_ |= 0x4081020000000ULL;
            op_disc.data_ ^= 0x4081020000000ULL;
            count += 4;
          }
        } else if (my_disc.lower_ & 0x20000000UL) {
          my_disc.data_ |= 0x4081000000000ULL;
          op_disc.data_ ^= 0x4081000000000ULL;
          count += 3;
        }
      } else if (my_disc.upper_ & 0x10UL) {
        my_disc.data_ |= 0x4080000000000ULL;
        op_disc.data_ ^= 0x4080000000000ULL;
        count += 2;
      }
    } else if (my_disc.upper_ & 0x800UL) {
      my_disc.data_ |= 0x4000000000000ULL;
      op_disc.data_ ^= 0x4000000000000ULL;
      count += 1;
    }
  }
  return count;
}

static int f_72(bit_matrix& my_disc, bit_matrix& op_disc) {
  int count = 0;
  if (op_disc.upper_ & 0x8000000UL) {
    if (op_disc.upper_ & 0x10000000UL) {
      if (op_disc.upper_ & 0x20000000UL) {
        if (op_disc.upper_ & 0x40000000UL) {
          if (my_disc.upper_ & 0x80000000UL) {
            my_disc.data_ |= 0x7800000000000000ULL;
            op_disc.data_ ^= 0x7800000000000000ULL;
            count += 4;
          }
        } else if (my_disc.upper_ & 0x40000000UL) {
          my_disc.data_ |= 0x3800000000000000ULL;
          op_disc.data_ ^= 0x3800000000000000ULL;
          count += 3;
        }
      } else if (my_disc.upper_ & 0x20000000UL) {
        my_disc.data_ |= 0x1800000000000000ULL;
        op_disc.data_ ^= 0x1800000000000000ULL;
        count += 2;
      }
    } else if (my_disc.upper_ & 0x10000000UL) {
      my_disc.data_ |= 0x800000000000000ULL;
      op_disc.data_ ^= 0x800000000000000ULL;
      count += 1;
    }
  }
  if (op_disc.upper_ & 0x2000000UL) {
    if (my_disc.upper_ & 0x1000000UL) {
      my_disc.data_ |= 0x200000000000000ULL;
      op_disc.data_ ^= 0x200000000000000ULL;
      count += 1;
    }
  }
  if (op_disc.upper_ & 0x40000UL) {
    if (op_disc.upper_ & 0x400UL) {
      if (op_disc.upper_ & 0x4UL) {
        if (op_disc.lower_ & 0x4000000UL) {
          if (op_disc.lower_ & 0x40000UL) {
            if (op_disc.lower_ & 0x400UL) {
              if (my_disc.lower_ & 0x4UL) {
                my_disc.data_ |= 0x4040404040400ULL;
                op_disc.data_ ^= 0x4040404040400ULL;
                count += 6;
              }
            } else if (my_disc.lower_ & 0x400UL) {
              my_disc.data_ |= 0x4040404040000ULL;
              op_disc.data_ ^= 0x4040404040000ULL;
              count += 5;
            }
          } else if (my_disc.lower_ & 0x40000UL) {
            my_disc.data_ |= 0x4040404000000ULL;
            op_disc.data_ ^= 0x4040404000000ULL;
            count += 4;
          }
        } else if (my_disc.lower_ & 0x4000000UL) {
          my_disc.data_ |= 0x4040400000000ULL;
          op_disc.data_ ^= 0x4040400000000ULL;
          count += 3;
        }
      } else if (my_disc.upper_ & 0x4UL) {
        my_disc.data_ |= 0x4040000000000ULL;
        op_disc.data_ ^= 0x4040000000000ULL;
        count += 2;
      }
    } else if (my_disc.upper_ & 0x400UL) {
      my_disc.data_ |= 0x4000000000000ULL;
      op_disc.data_ ^= 0x4000000000000ULL;
      count += 1;
    }
  }
  if (op_disc.upper_ & 0x80000UL) {
    if (op_disc.upper_ & 0x1000UL) {
      if (op_disc.upper_ & 0x20UL) {
        if (op_disc.lower_ & 0x40000000UL) {
          if (my_disc.lower_ & 0x800000UL) {
            my_disc.data_ |= 0x8102040000000ULL;
            op_disc.data_ ^= 0x8102040000000ULL;
            count += 4;
          }
        } else if (my_disc.lower_ & 0x40000000UL) {
          my_disc.data_ |= 0x8102000000000ULL;
          op_disc.data_ ^= 0x8102000000000ULL;
          count += 3;
        }
      } else if (my_disc.upper_ & 0x20UL) {
        my_disc.data_ |= 0x8100000000000ULL;
        op_disc.data_ ^= 0x8100000000000ULL;
        count += 2;
      }
    } else if (my_disc.upper_ & 0x1000UL) {
      my_disc.data_ |= 0x8000000000000ULL;
      op_disc.data_ ^= 0x8000000000000ULL;
      count += 1;
    }
  }
  if (op_disc.upper_ & 0x20000UL) {
    if (my_disc.upper_ & 0x100UL) {
      my_disc.data_ |= 0x2000000000000ULL;
      op_disc.data_ ^= 0x2000000000000ULL;
      count += 1;
    }
  }
  return count;
}

static int f_73(bit_matrix& my_disc, bit_matrix& op_disc) {
  int count = 0;
  if (op_disc.upper_ & 0x10000000UL) {
    if (op_disc.upper_ & 0x20000000UL) {
      if (op_disc.upper_ & 0x40000000UL) {
        if (my_disc.upper_ & 0x80000000UL) {
          my_disc.data_ |= 0x7000000000000000ULL;
          op_disc.data_ ^= 0x7000000000000000ULL;
          count += 3;
        }
      } else if (my_disc.upper_ & 0x40000000UL) {
        my_disc.data_ |= 0x3000000000000000ULL;
        op_disc.data_ ^= 0x3000000000000000ULL;
        count += 2;
      }
    } else if (my_disc.upper_ & 0x20000000UL) {
      my_disc.data_ |= 0x1000000000000000ULL;
      op_disc.data_ ^= 0x1000000000000000ULL;
      count += 1;
    }
  }
  if (op_disc.upper_ & 0x4000000UL) {
    if (op_disc.upper_ & 0x2000000UL) {
      if (my_disc.upper_ & 0x1000000UL) {
        my_disc.data_ |= 0x600000000000000ULL;
        op_disc.data_ ^= 0x600000000000000ULL;
        count += 2;
      }
    } else if (my_disc.upper_ & 0x2000000UL) {
      my_disc.data_ |= 0x400000000000000ULL;
      op_disc.data_ ^= 0x400000000000000ULL;
      count += 1;
    }
  }
  if (op_disc.upper_ & 0x80000UL) {
    if (op_disc.upper_ & 0x800UL) {
      if (op_disc.upper_ & 0x8UL) {
        if (op_disc.lower_ & 0x8000000UL) {
          if (op_disc.lower_ & 0x80000UL) {
            if (op_disc.lower_ & 0x800UL) {
              if (my_disc.lower_ & 0x8UL) {
                my_disc.data_ |= 0x8080808080800ULL;
                op_disc.data_ ^= 0x8080808080800ULL;
                count += 6;
              }
            } else if (my_disc.lower_ & 0x800UL) {
              my_disc.data_ |= 0x8080808080000ULL;
              op_disc.data_ ^= 0x8080808080000ULL;
              count += 5;
            }
          } else if (my_disc.lower_ & 0x80000UL) {
            my_disc.data_ |= 0x8080808000000ULL;
            op_disc.data_ ^= 0x8080808000000ULL;
            count += 4;
          }
        } else if (my_disc.lower_ & 0x8000000UL) {
          my_disc.data_ |= 0x8080800000000ULL;
          op_disc.data_ ^= 0x8080800000000ULL;
          count += 3;
        }
      } else if (my_disc.upper_ & 0x8UL) {
        my_disc.data_ |= 0x8080000000000ULL;
        op_disc.data_ ^= 0x8080000000000ULL;
        count += 2;
      }
    } else if (my_disc.upper_ & 0x800UL) {
      my_disc.data_ |= 0x8000000000000ULL;
      op_disc.data_ ^= 0x8000000000000ULL;
      count += 1;
    }
  }
  if (op_disc.upper_ & 0x100000UL) {
    if (op_disc.upper_ & 0x2000UL) {
      if (op_disc.upper_ & 0x40UL) {
        if (my_disc.lower_ & 0x80000000UL) {
          my_disc.data_ |= 0x10204000000000ULL;
          op_disc.data_ ^= 0x10204000000000ULL;
          count += 3;
        }
      } else if (my_disc.upper_ & 0x40UL) {
        my_disc.data_ |= 0x10200000000000ULL;
        op_disc.data_ ^= 0x10200000000000ULL;
        count += 2;
      }
    } else if (my_disc.upper_ & 0x2000UL) {
      my_disc.data_ |= 0x10000000000000ULL;
      op_disc.data_ ^= 0x10000000000000ULL;
      count += 1;
    }
  }
  if (op_disc.upper_ & 0x40000UL) {
    if (op_disc.upper_ & 0x200UL) {
      if (my_disc.upper_ & 0x1UL) {
        my_disc.data_ |= 0x4020000000000ULL;
        op_disc.data_ ^= 0x4020000000000ULL;
        count += 2;
      }
    } else if (my_disc.upper_ & 0x200UL) {
      my_disc.data_ |= 0x4000000000000ULL;
      op_disc.data_ ^= 0x4000000000000ULL;
      count += 1;
    }
  }
  return count;
}

static int f_74(bit_matrix& my_disc, bit_matrix& op_disc) {
  int count = 0;
  if (op_disc.upper_ & 0x20000000UL) {
    if (op_disc.upper_ & 0x40000000UL) {
      if (my_disc.upper_ & 0x80000000UL) {
        my_disc.data_ |= 0x6000000000000000ULL;
        op_disc.data_ ^= 0x6000000000000000ULL;
        count += 2;
      }
    } else if (my_disc.upper_ & 0x40000000UL) {
      my_disc.data_ |= 0x2000000000000000ULL;
      op_disc.data_ ^= 0x2000000000000000ULL;
      count += 1;
    }
  }
  if (op_disc.upper_ & 0x8000000UL) {
    if (op_disc.upper_ & 0x4000000UL) {
      if (op_disc.upper_ & 0x2000000UL) {
        if (my_disc.upper_ & 0x1000000UL) {
          my_disc.data_ |= 0xe00000000000000ULL;
          op_disc.data_ ^= 0xe00000000000000ULL;
          count += 3;
        }
      } else if (my_disc.upper_ & 0x2000000UL) {
        my_disc.data_ |= 0xc00000000000000ULL;
        op_disc.data_ ^= 0xc00000000000000ULL;
        count += 2;
      }
    } else if (my_disc.upper_ & 0x4000000UL) {
      my_disc.data_ |= 0x800000000000000ULL;
      op_disc.data_ ^= 0x800000000000000ULL;
      count += 1;
    }
  }
  if (op_disc.upper_ & 0x100000UL) {
    if (op_disc.upper_ & 0x1000UL) {
      if (op_disc.upper_ & 0x10UL) {
        if (op_disc.lower_ & 0x10000000UL) {
          if (op_disc.lower_ & 0x100000UL) {
            if (op_disc.lower_ & 0x1000UL) {
              if (my_disc.lower_ & 0x10UL) {
                my_disc.data_ |= 0x10101010101000ULL;
                op_disc.data_ ^= 0x10101010101000ULL;
                count += 6;
              }
            } else if (my_disc.lower_ & 0x1000UL) {
              my_disc.data_ |= 0x10101010100000ULL;
              op_disc.data_ ^= 0x10101010100000ULL;
              count += 5;
            }
          } else if (my_disc.lower_ & 0x100000UL) {
            my_disc.data_ |= 0x10101010000000ULL;
            op_disc.data_ ^= 0x10101010000000ULL;
            count += 4;
          }
        } else if (my_disc.lower_ & 0x10000000UL) {
          my_disc.data_ |= 0x10101000000000ULL;
          op_disc.data_ ^= 0x10101000000000ULL;
          count += 3;
        }
      } else if (my_disc.upper_ & 0x10UL) {
        my_disc.data_ |= 0x10100000000000ULL;
        op_disc.data_ ^= 0x10100000000000ULL;
        count += 2;
      }
    } else if (my_disc.upper_ & 0x1000UL) {
      my_disc.data_ |= 0x10000000000000ULL;
      op_disc.data_ ^= 0x10000000000000ULL;
      count += 1;
    }
  }
  if (op_disc.upper_ & 0x200000UL) {
    if (op_disc.upper_ & 0x4000UL) {
      if (my_disc.upper_ & 0x80UL) {
        my_disc.data_ |= 0x20400000000000ULL;
        op_disc.data_ ^= 0x20400000000000ULL;
        count += 2;
      }
    } else if (my_disc.upper_ & 0x4000UL) {
      my_disc.data_ |= 0x20000000000000ULL;
      op_disc.data_ ^= 0x20000000000000ULL;
      count += 1;
    }
  }
  if (op_disc.upper_ & 0x80000UL) {
    if (op_disc.upper_ & 0x400UL) {
      if (op_disc.upper_ & 0x2UL) {
        if (my_disc.lower_ & 0x1000000UL) {
          my_disc.data_ |= 0x8040200000000ULL;
          op_disc.data_ ^= 0x8040200000000ULL;
          count += 3;
        }
      } else if (my_disc.upper_ & 0x2UL) {
        my_disc.data_ |= 0x8040000000000ULL;
        op_disc.data_ ^= 0x8040000000000ULL;
        count += 2;
      }
    } else if (my_disc.upper_ & 0x400UL) {
      my_disc.data_ |= 0x8000000000000ULL;
      op_disc.data_ ^= 0x8000000000000ULL;
      count += 1;
    }
  }
  return count;
}

static int f_75(bit_matrix& my_disc, bit_matrix& op_disc) {
  int count = 0;
  if (op_disc.upper_ & 0x40000000UL) {
    if (my_disc.upper_ & 0x80000000UL) {
      my_disc.data_ |= 0x4000000000000000ULL;
      op_disc.data_ ^= 0x4000000000000000ULL;
      count += 1;
    }
  }
  if (op_disc.upper_ & 0x10000000UL) {
    if (op_disc.upper_ & 0x8000000UL) {
      if (op_disc.upper_ & 0x4000000UL) {
        if (op_disc.upper_ & 0x2000000UL) {
          if (my_disc.upper_ & 0x1000000UL) {
            my_disc.data_ |= 0x1e00000000000000ULL;
            op_disc.data_ ^= 0x1e00000000000000ULL;
            count += 4;
          }
        } else if (my_disc.upper_ & 0x2000000UL) {
          my_disc.data_ |= 0x1c00000000000000ULL;
          op_disc.data_ ^= 0x1c00000000000000ULL;
          count += 3;
        }
      } else if (my_disc.upper_ & 0x4000000UL) {
        my_disc.data_ |= 0x1800000000000000ULL;
        op_disc.data_ ^= 0x1800000000000000ULL;
        count += 2;
      }
    } else if (my_disc.upper_ & 0x8000000UL) {
      my_disc.data_ |= 0x1000000000000000ULL;
      op_disc.data_ ^= 0x1000000000000000ULL;
      count += 1;
    }
  }
  if (op_disc.upper_ & 0x200000UL) {
    if (op_disc.upper_ & 0x2000UL) {
      if (op_disc.upper_ & 0x20UL) {
        if (op_disc.lower_ & 0x20000000UL) {
          if (op_disc.lower_ & 0x200000UL) {
            if (op_disc.lower_ & 0x2000UL) {
              if (my_disc.lower_ & 0x20UL) {
                my_disc.data_ |= 0x20202020202000ULL;
                op_disc.data_ ^= 0x20202020202000ULL;
                count += 6;
              }
            } else if (my_disc.lower_ & 0x2000UL) {
              my_disc.data_ |= 0x20202020200000ULL;
              op_disc.data_ ^= 0x20202020200000ULL;
              count += 5;
            }
          } else if (my_disc.lower_ & 0x200000UL) {
            my_disc.data_ |= 0x20202020000000ULL;
            op_disc.data_ ^= 0x20202020000000ULL;
            count += 4;
          }
        } else if (my_disc.lower_ & 0x20000000UL) {
          my_disc.data_ |= 0x20202000000000ULL;
          op_disc.data_ ^= 0x20202000000000ULL;
          count += 3;
        }
      } else if (my_disc.upper_ & 0x20UL) {
        my_disc.data_ |= 0x20200000000000ULL;
        op_disc.data_ ^= 0x20200000000000ULL;
        count += 2;
      }
    } else if (my_disc.upper_ & 0x2000UL) {
      my_disc.data_ |= 0x20000000000000ULL;
      op_disc.data_ ^= 0x20000000000000ULL;
      count += 1;
    }
  }
  if (op_disc.upper_ & 0x400000UL) {
    if (my_disc.upper_ & 0x8000UL) {
      my_disc.data_ |= 0x40000000000000ULL;
      op_disc.data_ ^= 0x40000000000000ULL;
      count += 1;
    }
  }
  if (op_disc.upper_ & 0x100000UL) {
    if (op_disc.upper_ & 0x800UL) {
      if (op_disc.upper_ & 0x4UL) {
        if (op_disc.lower_ & 0x2000000UL) {
          if (my_disc.lower_ & 0x10000UL) {
            my_disc.data_ |= 0x10080402000000ULL;
            op_disc.data_ ^= 0x10080402000000ULL;
            count += 4;
          }
        } else if (my_disc.lower_ & 0x2000000UL) {
          my_disc.data_ |= 0x10080400000000ULL;
          op_disc.data_ ^= 0x10080400000000ULL;
          count += 3;
        }
      } else if (my_disc.upper_ & 0x4UL) {
        my_disc.data_ |= 0x10080000000000ULL;
        op_disc.data_ ^= 0x10080000000000ULL;
        count += 2;
      }
    } else if (my_disc.upper_ & 0x800UL) {
      my_disc.data_ |= 0x10000000000000ULL;
      op_disc.data_ ^= 0x10000000000000ULL;
      count += 1;
    }
  }
  return count;
}

static int f_76(bit_matrix& my_disc, bit_matrix& op_disc) {
  int count = 0;
  if (op_disc.upper_ & 0x20000000UL) {
    if (op_disc.upper_ & 0x10000000UL) {
      if (op_disc.upper_ & 0x8000000UL) {
        if (op_disc.upper_ & 0x4000000UL) {
          if (op_disc.upper_ & 0x2000000UL) {
            if (my_disc.upper_ & 0x1000000UL) {
              my_disc.data_ |= 0x3e00000000000000ULL;
              op_disc.data_ ^= 0x3e00000000000000ULL;
              count += 5;
            }
          } else if (my_disc.upper_ & 0x2000000UL) {
            my_disc.data_ |= 0x3c00000000000000ULL;
            op_disc.data_ ^= 0x3c00000000000000ULL;
            count += 4;
          }
        } else if (my_disc.upper_ & 0x4000000UL) {
          my_disc.data_ |= 0x3800000000000000ULL;
          op_disc.data_ ^= 0x3800000000000000ULL;
          count += 3;
        }
      } else if (my_disc.upper_ & 0x8000000UL) {
        my_disc.data_ |= 0x3000000000000000ULL;
        op_disc.data_ ^= 0x3000000000000000ULL;
        count += 2;
      }
    } else if (my_disc.upper_ & 0x10000000UL) {
      my_disc.data_ |= 0x2000000000000000ULL;
      op_disc.data_ ^= 0x2000000000000000ULL;
      count += 1;
    }
  }
  if (op_disc.upper_ & 0x400000UL) {
    if (op_disc.upper_ & 0x4000UL) {
      if (op_disc.upper_ & 0x40UL) {
        if (op_disc.lower_ & 0x40000000UL) {
          if (op_disc.lower_ & 0x400000UL) {
            if (op_disc.lower_ & 0x4000UL) {
              if (my_disc.lower_ & 0x40UL) {
                my_disc.data_ |= 0x40404040404000ULL;
                op_disc.data_ ^= 0x40404040404000ULL;
                count += 6;
              }
            } else if (my_disc.lower_ & 0x4000UL) {
              my_disc.data_ |= 0x40404040400000ULL;
              op_disc.data_ ^= 0x40404040400000ULL;
              count += 5;
            }
          } else if (my_disc.lower_ & 0x400000UL) {
            my_disc.data_ |= 0x40404040000000ULL;
            op_disc.data_ ^= 0x40404040000000ULL;
            count += 4;
          }
        } else if (my_disc.lower_ & 0x40000000UL) {
          my_disc.data_ |= 0x40404000000000ULL;
          op_disc.data_ ^= 0x40404000000000ULL;
          count += 3;
        }
      } else if (my_disc.upper_ & 0x40UL) {
        my_disc.data_ |= 0x40400000000000ULL;
        op_disc.data_ ^= 0x40400000000000ULL;
        count += 2;
      }
    } else if (my_disc.upper_ & 0x4000UL) {
      my_disc.data_ |= 0x40000000000000ULL;
      op_disc.data_ ^= 0x40000000000000ULL;
      count += 1;
    }
  }
  if (op_disc.upper_ & 0x200000UL) {
    if (op_disc.upper_ & 0x1000UL) {
      if (op_disc.upper_ & 0x8UL) {
        if (op_disc.lower_ & 0x4000000UL) {
          if (op_disc.lower_ & 0x20000UL) {
            if (my_disc.lower_ & 0x100UL) {
              my_disc.data_ |= 0x20100804020000ULL;
              op_disc.data_ ^= 0x20100804020000ULL;
              count += 5;
            }
          } else if (my_disc.lower_ & 0x20000UL) {
            my_disc.data_ |= 0x20100804000000ULL;
            op_disc.data_ ^= 0x20100804000000ULL;
            count += 4;
          }
        } else if (my_disc.lower_ & 0x4000000UL) {
          my_disc.data_ |= 0x20100800000000ULL;
          op_disc.data_ ^= 0x20100800000000ULL;
          count += 3;
        }
      } else if (my_disc.upper_ & 0x8UL) {
        my_disc.data_ |= 0x20100000000000ULL;
        op_disc.data_ ^= 0x20100000000000ULL;
        count += 2;
      }
    } else if (my_disc.upper_ & 0x1000UL) {
      my_disc.data_ |= 0x20000000000000ULL;
      op_disc.data_ ^= 0x20000000000000ULL;
      count += 1;
    }
  }
  return count;
}

static int f_77(bit_matrix& my_disc, bit_matrix& op_disc) {
  int count = 0;
  if (op_disc.upper_ & 0x40000000UL) {
    if (op_disc.upper_ & 0x20000000UL) {
      if (op_disc.upper_ & 0x10000000UL) {
        if (op_disc.upper_ & 0x8000000UL) {
          if (op_disc.upper_ & 0x4000000UL) {
            if (op_disc.upper_ & 0x2000000UL) {
              if (my_disc.upper_ & 0x1000000UL) {
                my_disc.data_ |= 0x7e00000000000000ULL;
                op_disc.data_ ^= 0x7e00000000000000ULL;
                count += 6;
              }
            } else if (my_disc.upper_ & 0x2000000UL) {
              my_disc.data_ |= 0x7c00000000000000ULL;
              op_disc.data_ ^= 0x7c00000000000000ULL;
              count += 5;
            }
          } else if (my_disc.upper_ & 0x4000000UL) {
            my_disc.data_ |= 0x7800000000000000ULL;
            op_disc.data_ ^= 0x7800000000000000ULL;
            count += 4;
          }
        } else if (my_disc.upper_ & 0x8000000UL) {
          my_disc.data_ |= 0x7000000000000000ULL;
          op_disc.data_ ^= 0x7000000000000000ULL;
          count += 3;
        }
      } else if (my_disc.upper_ & 0x10000000UL) {
        my_disc.data_ |= 0x6000000000000000ULL;
        op_disc.data_ ^= 0x6000000000000000ULL;
        count += 2;
      }
    } else if (my_disc.upper_ & 0x20000000UL) {
      my_disc.data_ |= 0x4000000000000000ULL;
      op_disc.data_ ^= 0x4000000000000000ULL;
      count += 1;
    }
  }
  if (op_disc.upper_ & 0x800000UL) {
    if (op_disc.upper_ & 0x8000UL) {
      if (op_disc.upper_ & 0x80UL) {
        if (op_disc.lower_ & 0x80000000UL) {
          if (op_disc.lower_ & 0x800000UL) {
            if (op_disc.lower_ & 0x8000UL) {
              if (my_disc.lower_ & 0x80UL) {
                my_disc.data_ |= 0x80808080808000ULL;
                op_disc.data_ ^= 0x80808080808000ULL;
                count += 6;
              }
            } else if (my_disc.lower_ & 0x8000UL) {
              my_disc.data_ |= 0x80808080800000ULL;
              op_disc.data_ ^= 0x80808080800000ULL;
              count += 5;
            }
          } else if (my_disc.lower_ & 0x800000UL) {
            my_disc.data_ |= 0x80808080000000ULL;
            op_disc.data_ ^= 0x80808080000000ULL;
            count += 4;
          }
        } else if (my_disc.lower_ & 0x80000000UL) {
          my_disc.data_ |= 0x80808000000000ULL;
          op_disc.data_ ^= 0x80808000000000ULL;
          count += 3;
        }
      } else if (my_disc.upper_ & 0x80UL) {
        my_disc.data_ |= 0x80800000000000ULL;
        op_disc.data_ ^= 0x80800000000000ULL;
        count += 2;
      }
    } else if (my_disc.upper_ & 0x8000UL) {
      my_disc.data_ |= 0x80000000000000ULL;
      op_disc.data_ ^= 0x80000000000000ULL;
      count += 1;
    }
  }
  if (op_disc.upper_ & 0x400000UL) {
    if (op_disc.upper_ & 0x2000UL) {
      if (op_disc.upper_ & 0x10UL) {
        if (op_disc.lower_ & 0x8000000UL) {
          if (op_disc.lower_ & 0x40000UL) {
            if (op_disc.lower_ & 0x200UL) {
              if (my_disc.lower_ & 0x1UL) {
                my_disc.data_ |= 0x40201008040200ULL;
                op_disc.data_ ^= 0x40201008040200ULL;
                count += 6;
              }
            } else if (my_disc.lower_ & 0x200UL) {
              my_disc.data_ |= 0x40201008040000ULL;
              op_disc.data_ ^= 0x40201008040000ULL;
              count += 5;
            }
          } else if (my_disc.lower_ & 0x40000UL) {
            my_disc.data_ |= 0x40201008000000ULL;
            op_disc.data_ ^= 0x40201008000000ULL;
            count += 4;
          }
        } else if (my_disc.lower_ & 0x8000000UL) {
          my_disc.data_ |= 0x40201000000000ULL;
          op_disc.data_ ^= 0x40201000000000ULL;
          count += 3;
        }
      } else if (my_disc.upper_ & 0x10UL) {
        my_disc.data_ |= 0x40200000000000ULL;
        op_disc.data_ ^= 0x40200000000000ULL;
        count += 2;
      }
    } else if (my_disc.upper_ & 0x2000UL) {
      my_disc.data_ |= 0x40000000000000ULL;
      op_disc.data_ ^= 0x40000000000000ULL;
      count += 1;
    }
  }
  return count;
}

static int g_00(const bit_matrix& my_disc, const bit_matrix& op_disc) {
  int count = 0;
  if (op_disc.lower_ & 0x2UL) {
    if (op_disc.lower_ & 0x4UL) {
      if (op_disc.lower_ & 0x8UL) {
        if (op_disc.lower_ & 0x10UL) {
          if (op_disc.lower_ & 0x20UL) {
            if (op_disc.lower_ & 0x40UL) {
              if (my_disc.lower_ & 0x80UL) {
                count += 6;
              }
            } else if (my_disc.lower_ & 0x40UL) {
              count += 5;
            }
          } else if (my_disc.lower_ & 0x20UL) {
            count += 4;
          }
        } else if (my_disc.lower_ & 0x10UL) {
          count += 3;
        }
      } else if (my_disc.lower_ & 0x8UL) {
        count += 2;
      }
    } else if (my_disc.lower_ & 0x4UL) {
      count += 1;
    }
  }
  if (op_disc.lower_ & 0x100UL) {
    if (op_disc.lower_ & 0x10000UL) {
      if (op_disc.lower_ & 0x1000000UL) {
        if (op_disc.upper_ & 0x1UL) {
          if (op_disc.upper_ & 0x100UL) {
            if (op_disc.upper_ & 0x10000UL) {
              if (my_disc.upper_ & 0x1000000UL) {
                count += 6;
              }
            } else if (my_disc.upper_ & 0x10000UL) {
              count += 5;
            }
          } else if (my_disc.upper_ & 0x100UL) {
            count += 4;
          }
        } else if (my_disc.upper_ & 0x1UL) {
          count += 3;
        }
      } else if (my_disc.lower_ & 0x1000000UL) {
        count += 2;
      }
    } else if (my_disc.lower_ & 0x10000UL) {
      count += 1;
    }
  }
  if (op_disc.lower_ & 0x200UL) {
    if (op_disc.lower_ & 0x40000UL) {
      if (op_disc.lower_ & 0x8000000UL) {
        if (op_disc.upper_ & 0x10UL) {
          if (op_disc.upper_ & 0x2000UL) {
            if (op_disc.upper_ & 0x400000UL) {
              if (my_disc.upper_ & 0x80000000UL) {
                count += 6;
              }
            } else if (my_disc.upper_ & 0x400000UL) {
              count += 5;
            }
          } else if (my_disc.upper_ & 0x2000UL) {
            count += 4;
          }
        } else if (my_disc.upper_ & 0x10UL) {
          count += 3;
        }
      } else if (my_disc.lower_ & 0x8000000UL) {
        count += 2;
      }
    } else if (my_disc.lower_ & 0x40000UL) {
      count += 1;
    }
  }
  return count;
}

static int g_01(const bit_matrix& my_disc, const bit_matrix& op_disc) {
  int count = 0;
  if (op_disc.lower_ & 0x4UL) {
    if (op_disc.lower_ & 0x8UL) {
      if (op_disc.lower_ & 0x10UL) {
        if (op_disc.lower_ & 0x20UL) {
          if (op_disc.lower_ & 0x40UL) {
            if (my_disc.lower_ & 0x80UL) {
              count += 5;
            }
          } else if (my_disc.lower_ & 0x40UL) {
            count += 4;
          }
        } else if (my_disc.lower_ & 0x20UL) {
          count += 3;
        }
      } else if (my_disc.lower_ & 0x10UL) {
        count += 2;
      }
    } else if (my_disc.lower_ & 0x8UL) {
      count += 1;
    }
  }
  if (op_disc.lower_ & 0x200UL) {
    if (op_disc.lower_ & 0x20000UL) {
      if (op_disc.lower_ & 0x2000000UL) {
        if (op_disc.upper_ & 0x2UL) {
          if (op_disc.upper_ & 0x200UL) {
            if (op_disc.upper_ & 0x20000UL) {
              if (my_disc.upper_ & 0x2000000UL) {
                count += 6;
              }
            } else if (my_disc.upper_ & 0x20000UL) {
              count += 5;
            }
          } else if (my_disc.upper_ & 0x200UL) {
            count += 4;
          }
        } else if (my_disc.upper_ & 0x2UL) {
          count += 3;
        }
      } else if (my_disc.lower_ & 0x2000000UL) {
        count += 2;
      }
    } else if (my_disc.lower_ & 0x20000UL) {
      count += 1;
    }
  }
  if (op_disc.lower_ & 0x400UL) {
    if (op_disc.lower_ & 0x80000UL) {
      if (op_disc.lower_ & 0x10000000UL) {
        if (op_disc.upper_ & 0x20UL) {
          if (op_disc.upper_ & 0x4000UL) {
            if (my_disc.upper_ & 0x800000UL) {
              count += 5;
            }
          } else if (my_disc.upper_ & 0x4000UL) {
            count += 4;
          }
        } else if (my_disc.upper_ & 0x20UL) {
          count += 3;
        }
      } else if (my_disc.lower_ & 0x10000000UL) {
        count += 2;
      }
    } else if (my_disc.lower_ & 0x80000UL) {
      count += 1;
    }
  }
  return count;
}

static int g_02(const bit_matrix& my_disc, const bit_matrix& op_disc) {
  int count = 0;
  if (op_disc.lower_ & 0x8UL) {
    if (op_disc.lower_ & 0x10UL) {
      if (op_disc.lower_ & 0x20UL) {
        if (op_disc.lower_ & 0x40UL) {
          if (my_disc.lower_ & 0x80UL) {
            count += 4;
          }
        } else if (my_disc.lower_ & 0x40UL) {
          count += 3;
        }
      } else if (my_disc.lower_ & 0x20UL) {
        count += 2;
      }
    } else if (my_disc.lower_ & 0x10UL) {
      count += 1;
    }
  }
  if (op_disc.lower_ & 0x2UL) {
    if (my_disc.lower_ & 0x1UL) {
      count += 1;
    }
  }
  if (op_disc.lower_ & 0x400UL) {
    if (op_disc.lower_ & 0x40000UL) {
      if (op_disc.lower_ & 0x4000000UL) {
        if (op_disc.upper_ & 0x4UL) {
          if (op_disc.upper_ & 0x400UL) {
            if (op_disc.upper_ & 0x40000UL) {
              if (my_disc.upper_ & 0x4000000UL) {
                count += 6;
              }
            } else if (my_disc.upper_ & 0x40000UL) {
              count += 5;
            }
          } else if (my_disc.upper_ & 0x400UL) {
            count += 4;
          }
        } else if (my_disc.upper_ & 0x4UL) {
          count += 3;
        }
      } else if (my_disc.lower_ & 0x4000000UL) {
        count += 2;
      }
    } else if (my_disc.lower_ & 0x40000UL) {
      count += 1;
    }
  }
  if (op_disc.lower_ & 0x800UL) {
    if (op_disc.lower_ & 0x100000UL) {
      if (op_disc.lower_ & 0x20000000UL) {
        if (op_disc.upper_ & 0x40UL) {
          if (my_disc.upper_ & 0x8000UL) {
            count += 4;
          }
        } else if (my_disc.upper_ & 0x40UL) {
          count += 3;
        }
      } else if (my_disc.lower_ & 0x20000000UL) {
        count += 2;
      }
    } else if (my_disc.lower_ & 0x100000UL) {
      count += 1;
    }
  }
  if (op_disc.lower_ & 0x200UL) {
    if (my_disc.lower_ & 0x10000UL) {
      count += 1;
    }
  }
  return count;
}

static int g_03(const bit_matrix& my_disc, const bit_matrix& op_disc) {
  int count = 0;
  if (op_disc.lower_ & 0x10UL) {
    if (op_disc.lower_ & 0x20UL) {
      if (op_disc.lower_ & 0x40UL) {
        if (my_disc.lower_ & 0x80UL) {
          count += 3;
        }
      } else if (my_disc.lower_ & 0x40UL) {
        count += 2;
      }
    } else if (my_disc.lower_ & 0x20UL) {
      count += 1;
    }
  }
  if (op_disc.lower_ & 0x4UL) {
    if (op_disc.lower_ & 0x2UL) {
      if (my_disc.lower_ & 0x1UL) {
        count += 2;
      }
    } else if (my_disc.lower_ & 0x2UL) {
      count += 1;
    }
  }
  if (op_disc.lower_ & 0x800UL) {
    if (op_disc.lower_ & 0x80000UL) {
      if (op_disc.lower_ & 0x8000000UL) {
        if (op_disc.upper_ & 0x8UL) {
          if (op_disc.upper_ & 0x800UL) {
            if (op_disc.upper_ & 0x80000UL) {
              if (my_disc.upper_ & 0x8000000UL) {
                count += 6;
              }
            } else if (my_disc.upper_ & 0x80000UL) {
              count += 5;
            }
          } else if (my_disc.upper_ & 0x800UL) {
            count += 4;
          }
        } else if (my_disc.upper_ & 0x8UL) {
          count += 3;
        }
      } else if (my_disc.lower_ & 0x8000000UL) {
        count += 2;
      }
    } else if (my_disc.lower_ & 0x80000UL) {
      count += 1;
    }
  }
  if (op_disc.lower_ & 0x1000UL) {
    if (op_disc.lower_ & 0x200000UL) {
      if (op_disc.lower_ & 0x40000000UL) {
        if (my_disc.upper_ & 0x80UL) {
          count += 3;
        }
      } else if (my_disc.lower_ & 0x40000000UL) {
        count += 2;
      }
    } else if (my_disc.lower_ & 0x200000UL) {
      count += 1;
    }
  }
  if (op_disc.lower_ & 0x400UL) {
    if (op_disc.lower_ & 0x20000UL) {
      if (my_disc.lower_ & 0x1000000UL) {
        count += 2;
      }
    } else if (my_disc.lower_ & 0x20000UL) {
      count += 1;
    }
  }
  return count;
}

static int g_04(const bit_matrix& my_disc, const bit_matrix& op_disc) {
  int count = 0;
  if (op_disc.lower_ & 0x20UL) {
    if (op_disc.lower_ & 0x40UL) {
      if (my_disc.lower_ & 0x80UL) {
        count += 2;
      }
    } else if (my_disc.lower_ & 0x40UL) {
      count += 1;
    }
  }
  if (op_disc.lower_ & 0x8UL) {
    if (op_disc.lower_ & 0x4UL) {
      if (op_disc.lower_ & 0x2UL) {
        if (my_disc.lower_ & 0x1UL) {
          count += 3;
        }
      } else if (my_disc.lower_ & 0x2UL) {
        count += 2;
      }
    } else if (my_disc.lower_ & 0x4UL) {
      count += 1;
    }
  }
  if (op_disc.lower_ & 0x1000UL) {
    if (op_disc.lower_ & 0x100000UL) {
      if (op_disc.lower_ & 0x10000000UL) {
        if (op_disc.upper_ & 0x10UL) {
          if (op_disc.upper_ & 0x1000UL) {
            if (op_disc.upper_ & 0x100000UL) {
              if (my_disc.upper_ & 0x10000000UL) {
                count += 6;
              }
            } else if (my_disc.upper_ & 0x100000UL) {
              count += 5;
            }
          } else if (my_disc.upper_ & 0x1000UL) {
            count += 4;
          }
        } else if (my_disc.upper_ & 0x10UL) {
          count += 3;
        }
      } else if (my_disc.lower_ & 0x10000000UL) {
        count += 2;
      }
    } else if (my_disc.lower_ & 0x100000UL) {
      count += 1;
    }
  }
  if (op_disc.lower_ & 0x2000UL) {
    if (op_disc.lower_ & 0x400000UL) {
      if (my_disc.lower_ & 0x80000000UL) {
        count += 2;
      }
    } else if (my_disc.lower_ & 0x400000UL) {
      count += 1;
    }
  }
  if (op_disc.lower_ & 0x800UL) {
    if (op_disc.lower_ & 0x40000UL) {
      if (op_disc.lower_ & 0x2000000UL) {
        if (my_disc.upper_ & 0x1UL) {
          count += 3;
        }
      } else if (my_disc.lower_ & 0x2000000UL) {
        count += 2;
      }
    } else if (my_disc.lower_ & 0x40000UL) {
      count += 1;
    }
  }
  return count;
}

static int g_05(const bit_matrix& my_disc, const bit_matrix& op_disc) {
  int count = 0;
  if (op_disc.lower_ & 0x40UL) {
    if (my_disc.lower_ & 0x80UL) {
      count += 1;
    }
  }
  if (op_disc.lower_ & 0x10UL) {
    if (op_disc.lower_ & 0x8UL) {
      if (op_disc.lower_ & 0x4UL) {
        if (op_disc.lower_ & 0x2UL) {
          if (my_disc.lower_ & 0x1UL) {
            count += 4;
          }
        } else if (my_disc.lower_ & 0x2UL) {
          count += 3;
        }
      } else if (my_disc.lower_ & 0x4UL) {
        count += 2;
      }
    } else if (my_disc.lower_ & 0x8UL) {
      count += 1;
    }
  }
  if (op_disc.lower_ & 0x2000UL) {
    if (op_disc.lower_ & 0x200000UL) {
      if (op_disc.lower_ & 0x20000000UL) {
        if (op_disc.upper_ & 0x20UL) {
          if (op_disc.upper_ & 0x2000UL) {
            if (op_disc.upper_ & 0x200000UL) {
              if (my_disc.upper_ & 0x20000000UL) {
                count += 6;
              }
            } else if (my_disc.upper_ & 0x200000UL) {
              count += 5;
            }
          } else if (my_disc.upper_ & 0x2000UL) {
            count += 4;
          }
        } else if (my_disc.upper_ & 0x20UL) {
          count += 3;
        }
      } else if (my_disc.lower_ & 0x20000000UL) {
        count += 2;
      }
    } else if (my_disc.lower_ & 0x200000UL) {
      count += 1;
    }
  }
  if (op_disc.lower_ & 0x4000UL) {
    if (my_disc.lower_ & 0x800000UL) {
      count += 1;
    }
  }
  if (op_disc.lower_ & 0x1000UL) {
    if (op_disc.lower_ & 0x80000UL) {
      if (op_disc.lower_ & 0x4000000UL) {
        if (op_disc.upper_ & 0x2UL) {
          if (my_disc.upper_ & 0x100UL) {
            count += 4;
          }
        } else if (my_disc.upper_ & 0x2UL) {
          count += 3;
        }
      } else if (my_disc.lower_ & 0x4000000UL) {
        count += 2;
      }
    } else if (my_disc.lower_ & 0x80000UL) {
      count += 1;
    }
  }
  return count;
}

static int g_06(const bit_matrix& my_disc, const bit_matrix& op_disc) {
  int count = 0;
  if (op_disc.lower_ & 0x20UL) {
    if (op_disc.lower_ & 0x10UL) {
      if (op_disc.lower_ & 0x8UL) {
        if (op_disc.lower_ & 0x4UL) {
          if (op_disc.lower_ & 0x2UL) {
            if (my_disc.lower_ & 0x1UL) {
              count += 5;
            }
          } else if (my_disc.lower_ & 0x2UL) {
            count += 4;
          }
        } else if (my_disc.lower_ & 0x4UL) {
          count += 3;
        }
      } else if (my_disc.lower_ & 0x8UL) {
        count += 2;
      }
    } else if (my_disc.lower_ & 0x10UL) {
      count += 1;
    }
  }
  if (op_disc.lower_ & 0x4000UL) {
    if (op_disc.lower_ & 0x400000UL) {
      if (op_disc.lower_ & 0x40000000UL) {
        if (op_disc.upper_ & 0x40UL) {
          if (op_disc.upper_ & 0x4000UL) {
            if (op_disc.upper_ & 0x400000UL) {
              if (my_disc.upper_ & 0x40000000UL) {
                count += 6;
              }
            } else if (my_disc.upper_ & 0x400000UL) {
              count += 5;
            }
          } else if (my_disc.upper_ & 0x4000UL) {
            count += 4;
          }
        } else if (my_disc.upper_ & 0x40UL) {
          count += 3;
        }
      } else if (my_disc.lower_ & 0x40000000UL) {
        count += 2;
      }
    } else if (my_disc.lower_ & 0x400000UL) {
      count += 1;
    }
  }
  if (op_disc.lower_ & 0x2000UL) {
    if (op_disc.lower_ & 0x100000UL) {
      if (op_disc.lower_ & 0x8000000UL) {
        if (op_disc.upper_ & 0x4UL) {
          if (op_disc.upper_ & 0x200UL) {
            if (my_disc.upper_ & 0x10000UL) {
              count += 5;
            }
          } else if (my_disc.upper_ & 0x200UL) {
            count += 4;
          }
        } else if (my_disc.upper_ & 0x4UL) {
          count += 3;
        }
      } else if (my_disc.lower_ & 0x8000000UL) {
        count += 2;
      }
    } else if (my_disc.lower_ & 0x100000UL) {
      count += 1;
    }
  }
  return count;
}

static int g_07(const bit_matrix& my_disc, const bit_matrix& op_disc) {
  int count = 0;
  if (op_disc.lower_ & 0x40UL) {
    if (op_disc.lower_ & 0x20UL) {
      if (op_disc.lower_ & 0x10UL) {
        if (op_disc.lower_ & 0x8UL) {
          if (op_disc.lower_ & 0x4UL) {
            if (op_disc.lower_ & 0x2UL) {
              if (my_disc.lower_ & 0x1UL) {
                count += 6;
              }
            } else if (my_disc.lower_ & 0x2UL) {
              count += 5;
            }
          } else if (my_disc.lower_ & 0x4UL) {
            count += 4;
          }
        } else if (my_disc.lower_ & 0x8UL) {
          count += 3;
        }
      } else if (my_disc.lower_ & 0x10UL) {
        count += 2;
      }
    } else if (my_disc.lower_ & 0x20UL) {
      count += 1;
    }
  }
  if (op_disc.lower_ & 0x8000UL) {
    if (op_disc.lower_ & 0x800000UL) {
      if (op_disc.lower_ & 0x80000000UL) {
        if (op_disc.upper_ & 0x80UL) {
          if (op_disc.upper_ & 0x8000UL) {
            if (op_disc.upper_ & 0x800000UL) {
              if (my_disc.upper_ & 0x80000000UL) {
                count += 6;
              }
            } else if (my_disc.upper_ & 0x800000UL) {
              count += 5;
            }
          } else if (my_disc.upper_ & 0x8000UL) {
            count += 4;
          }
        } else if (my_disc.upper_ & 0x80UL) {
          count += 3;
        }
      } else if (my_disc.lower_ & 0x80000000UL) {
        count += 2;
      }
    } else if (my_disc.lower_ & 0x800000UL) {
      count += 1;
    }
  }
  if (op_disc.lower_ & 0x4000UL) {
    if (op_disc.lower_ & 0x200000UL) {
      if (op_disc.lower_ & 0x10000000UL) {
        if (op_disc.upper_ & 0x8UL) {
          if (op_disc.upper_ & 0x400UL) {
            if (op_disc.upper_ & 0x20000UL) {
              if (my_disc.upper_ & 0x1000000UL) {
                count += 6;
              }
            } else if (my_disc.upper_ & 0x20000UL) {
              count += 5;
            }
          } else if (my_disc.upper_ & 0x400UL) {
            count += 4;
          }
        } else if (my_disc.upper_ & 0x8UL) {
          count += 3;
        }
      } else if (my_disc.lower_ & 0x10000000UL) {
        count += 2;
      }
    } else if (my_disc.lower_ & 0x200000UL) {
      count += 1;
    }
  }
  return count;
}

static int g_10(const bit_matrix& my_disc, const bit_matrix& op_disc) {
  int count = 0;
  if (op_disc.lower_ & 0x200UL) {
    if (op_disc.lower_ & 0x400UL) {
      if (op_disc.lower_ & 0x800UL) {
        if (op_disc.lower_ & 0x1000UL) {
          if (op_disc.lower_ & 0x2000UL) {
            if (op_disc.lower_ & 0x4000UL) {
              if (my_disc.lower_ & 0x8000UL) {
                count += 6;
              }
            } else if (my_disc.lower_ & 0x4000UL) {
              count += 5;
            }
          } else if (my_disc.lower_ & 0x2000UL) {
            count += 4;
          }
        } else if (my_disc.lower_ & 0x1000UL) {
          count += 3;
        }
      } else if (my_disc.lower_ & 0x800UL) {
        count += 2;
      }
    } else if (my_disc.lower_ & 0x400UL) {
      count += 1;
    }
  }
  if (op_disc.lower_ & 0x10000UL) {
    if (op_disc.lower_ & 0x1000000UL) {
      if (op_disc.upper_ & 0x1UL) {
        if (op_disc.upper_ & 0x100UL) {
          if (op_disc.upper_ & 0x10000UL) {
            if (my_disc.upper_ & 0x1000000UL) {
              count += 5;
            }
          } else if (my_disc.upper_ & 0x10000UL) {
            count += 4;
          }
        } else if (my_disc.upper_ & 0x100UL) {
          count += 3;
        }
      } else if (my_disc.upper_ & 0x1UL) {
        count += 2;
      }
    } else if (my_disc.lower_ & 0x1000000UL) {
      count += 1;
    }
  }
  if (op_disc.lower_ & 0x20000UL) {
    if (op_disc.lower_ & 0x4000000UL) {
      if (op_disc.upper_ & 0x8UL) {
        if (op_disc.upper_ & 0x1000UL) {
          if (op_disc.upper_ & 0x200000UL) {
            if (my_disc.upper_ & 0x40000000UL) {
              count += 5;
            }
          } else if (my_disc.upper_ & 0x200000UL) {
            count += 4;
          }
        } else if (my_disc.upper_ & 0x1000UL) {
          count += 3;
        }
      } else if (my_disc.upper_ & 0x8UL) {
        count += 2;
      }
    } else if (my_disc.lower_ & 0x4000000UL) {
      count += 1;
    }
  }
  return count;
}

static int g_11(const bit_matrix& my_disc, const bit_matrix& op_disc) {
  int count = 0;
  if (op_disc.lower_ & 0x400UL) {
    if (op_disc.lower_ & 0x800UL) {
      if (op_disc.lower_ & 0x1000UL) {
        if (op_disc.lower_ & 0x2000UL) {
          if (op_disc.lower_ & 0x4000UL) {
            if (my_disc.lower_ & 0x8000UL) {
              count += 5;
            }
          } else if (my_disc.lower_ & 0x4000UL) {
            count += 4;
          }
        } else if (my_disc.lower_ & 0x2000UL) {
          count += 3;
        }
      } else if (my_disc.lower_ & 0x1000UL) {
        count += 2;
      }
    } else if (my_disc.lower_ & 0x800UL) {
      count += 1;
    }
  }
  if (op_disc.lower_ & 0x20000UL) {
    if (op_disc.lower_ & 0x2000000UL) {
      if (op_disc.upper_ & 0x2UL) {
        if (op_disc.upper_ & 0x200UL) {
          if (op_disc.upper_ & 0x20000UL) {
            if (my_disc.upper_ & 0x2000000UL) {
              count += 5;
            }
          } else if (my_disc.upper_ & 0x20000UL) {
            count += 4;
          }
        } else if (my_disc.upper_ & 0x200UL) {
          count += 3;
        }
      } else if (my_disc.upper_ & 0x2UL) {
        count += 2;
      }
    } else if (my_disc.lower_ & 0x2000000UL) {
      count += 1;
    }
  }
  if (op_disc.lower_ & 0x40000UL) {
    if (op_disc.lower_ & 0x8000000UL) {
      if (op_disc.upper_ & 0x10UL) {
        if (op_disc.upper_ & 0x2000UL) {
          if (op_disc.upper_ & 0x400000UL) {
            if (my_disc.upper_ & 0x80000000UL) {
              count += 5;
            }
          } else if (my_disc.upper_ & 0x400000UL) {
            count += 4;
          }
        } else if (my_disc.upper_ & 0x2000UL) {
          count += 3;
        }
      } else if (my_disc.upper_ & 0x10UL) {
        count += 2;
      }
    } else if (my_disc.lower_ & 0x8000000UL) {
      count += 1;
    }
  }
  return count;
}

static int g_12(const bit_matrix& my_disc, const bit_matrix& op_disc) {
  int count = 0;
  if (op_disc.lower_ & 0x800UL) {
    if (op_disc.lower_ & 0x1000UL) {
      if (op_disc.lower_ & 0x2000UL) {
        if (op_disc.lower_ & 0x4000UL) {
          if (my_disc.lower_ & 0x8000UL) {
            count += 4;
          }
        } else if (my_disc.lower_ & 0x4000UL) {
          count += 3;
        }
      } else if (my_disc.lower_ & 0x2000UL) {
        count += 2;
      }
    } else if (my_disc.lower_ & 0x1000UL) {
      count += 1;
    }
  }
  if (op_disc.lower_ & 0x200UL) {
    if (my_disc.lower_ & 0x100UL) {
      count += 1;
    }
  }
  if (op_disc.lower_ & 0x40000UL) {
    if (op_disc.lower_ & 0x4000000UL) {
      if (op_disc.upper_ & 0x4UL) {
        if (op_disc.upper_ & 0x400UL) {
          if (op_disc.upper_ & 0x40000UL) {
            if (my_disc.upper_ & 0x4000000UL) {
              count += 5;
            }
          } else if (my_disc.upper_ & 0x40000UL) {
            count += 4;
          }
        } else if (my_disc.upper_ & 0x400UL) {
          count += 3;
        }
      } else if (my_disc.upper_ & 0x4UL) {
        count += 2;
      }
    } else if (my_disc.lower_ & 0x4000000UL) {
      count += 1;
    }
  }
  if (op_disc.lower_ & 0x80000UL) {
    if (op_disc.lower_ & 0x10000000UL) {
      if (op_disc.upper_ & 0x20UL) {
        if (op_disc.upper_ & 0x4000UL) {
          if (my_disc.upper_ & 0x800000UL) {
            count += 4;
          }
        } else if (my_disc.upper_ & 0x4000UL) {
          count += 3;
        }
      } else if (my_disc.upper_ & 0x20UL) {
        count += 2;
      }
    } else if (my_disc.lower_ & 0x10000000UL) {
      count += 1;
    }
  }
  if (op_disc.lower_ & 0x20000UL) {
    if (my_disc.lower_ & 0x1000000UL) {
      count += 1;
    }
  }
  return count;
}

static int g_13(const bit_matrix& my_disc, const bit_matrix& op_disc) {
  int count = 0;
  if (op_disc.lower_ & 0x1000UL) {
    if (op_disc.lower_ & 0x2000UL) {
      if (op_disc.lower_ & 0x4000UL) {
        if (my_disc.lower_ & 0x8000UL) {
          count += 3;
        }
      } else if (my_disc.lower_ & 0x4000UL) {
        count += 2;
      }
    } else if (my_disc.lower_ & 0x2000UL) {
      count += 1;
    }
  }
  if (op_disc.lower_ & 0x400UL) {
    if (op_disc.lower_ & 0x200UL) {
      if (my_disc.lower_ & 0x100UL) {
        count += 2;
      }
    } else if (my_disc.lower_ & 0x200UL) {
      count += 1;
    }
  }
  if (op_disc.lower_ & 0x80000UL) {
    if (op_disc.lower_ & 0x8000000UL) {
      if (op_disc.upper_ & 0x8UL) {
        if (op_disc.upper_ & 0x800UL) {
          if (op_disc.upper_ & 0x80000UL) {
            if (my_disc.upper_ & 0x8000000UL) {
              count += 5;
            }
          } else if (my_disc.upper_ & 0x80000UL) {
            count += 4;
          }
        } else if (my_disc.upper_ & 0x800UL) {
          count += 3;
        }
      } else if (my_disc.upper_ & 0x8UL) {
        count += 2;
      }
    } else if (my_disc.lower_ & 0x8000000UL) {
      count += 1;
    }
  }
  if (op_disc.lower_ & 0x100000UL) {
    if (op_disc.lower_ & 0x20000000UL) {
      if (op_disc.upper_ & 0x40UL) {
        if (my_disc.upper_ & 0x8000UL) {
          count += 3;
        }
      } else if (my_disc.upper_ & 0x40UL) {
        count += 2;
      }
    } else if (my_disc.lower_ & 0x20000000UL) {
      count += 1;
    }
  }
  if (op_disc.lower_ & 0x40000UL) {
    if (op_disc.lower_ & 0x2000000UL) {
      if (my_disc.upper_ & 0x1UL) {
        count += 2;
      }
    } else if (my_disc.lower_ & 0x2000000UL) {
      count += 1;
    }
  }
  return count;
}

static int g_14(const bit_matrix& my_disc, const bit_matrix& op_disc) {
  int count = 0;
  if (op_disc.lower_ & 0x2000UL) {
    if (op_disc.lower_ & 0x4000UL) {
      if (my_disc.lower_ & 0x8000UL) {
        count += 2;
      }
    } else if (my_disc.lower_ & 0x4000UL) {
      count += 1;
    }
  }
  if (op_disc.lower_ & 0x800UL) {
    if (op_disc.lower_ & 0x400UL) {
      if (op_disc.lower_ & 0x200UL) {
        if (my_disc.lower_ & 0x100UL) {
          count += 3;
        }
      } else if (my_disc.lower_ & 0x200UL) {
        count += 2;
      }
    } else if (my_disc.lower_ & 0x400UL) {
      count += 1;
    }
  }
  if (op_disc.lower_ & 0x100000UL) {
    if (op_disc.lower_ & 0x10000000UL) {
      if (op_disc.upper_ & 0x10UL) {
        if (op_disc.upper_ & 0x1000UL) {
          if (op_disc.upper_ & 0x100000UL) {
            if (my_disc.upper_ & 0x10000000UL) {
              count += 5;
            }
          } else if (my_disc.upper_ & 0x100000UL) {
            count += 4;
          }
        } else if (my_disc.upper_ & 0x1000UL) {
          count += 3;
        }
      } else if (my_disc.upper_ & 0x10UL) {
        count += 2;
      }
    } else if (my_disc.lower_ & 0x10000000UL) {
      count += 1;
    }
  }
  if (op_disc.lower_ & 0x200000UL) {
    if (op_disc.lower_ & 0x40000000UL) {
      if (my_disc.upper_ & 0x80UL) {
        count += 2;
      }
    } else if (my_disc.lower_ & 0x40000000UL) {
      count += 1;
    }
  }
  if (op_disc.lower_ & 0x80000UL) {
    if (op_disc.lower_ & 0x4000000UL) {
      if (op_disc.upper_ & 0x2UL) {
        if (my_disc.upper_ & 0x100UL) {
          count += 3;
        }
      } else if (my_disc.upper_ & 0x2UL) {
        count += 2;
      }
    } else if (my_disc.lower_ & 0x4000000UL) {
      count += 1;
    }
  }
  return count;
}

static int g_15(const bit_matrix& my_disc, const bit_matrix& op_disc) {
  int count = 0;
  if (op_disc.lower_ & 0x4000UL) {
    if (my_disc.lower_ & 0x8000UL) {
      count += 1;
    }
  }
  if (op_disc.lower_ & 0x1000UL) {
    if (op_disc.lower_ & 0x800UL) {
      if (op_disc.lower_ & 0x400UL) {
        if (op_disc.lower_ & 0x200UL) {
          if (my_disc.lower_ & 0x100UL) {
            count += 4;
          }
        } else if (my_disc.lower_ & 0x200UL) {
          count += 3;
        }
      } else if (my_disc.lower_ & 0x400UL) {
        count += 2;
      }
    } else if (my_disc.lower_ & 0x800UL) {
      count += 1;
    }
  }
  if (op_disc.lower_ & 0x200000UL) {
    if (op_disc.lower_ & 0x20000000UL) {
      if (op_disc.upper_ & 0x20UL) {
        if (op_disc.upper_ & 0x2000UL) {
          if (op_disc.upper_ & 0x200000UL) {
            if (my_disc.upper_ & 0x20000000UL) {
              count += 5;
            }
          } else if (my_disc.upper_ & 0x200000UL) {
            count += 4;
          }
        } else if (my_disc.upper_ & 0x2000UL) {
          count += 3;
        }
      } else if (my_disc.upper_ & 0x20UL) {
        count += 2;
      }
    } else if (my_disc.lower_ & 0x20000000UL) {
      count += 1;
    }
  }
  if (op_disc.lower_ & 0x400000UL) {
    if (my_disc.lower_ & 0x80000000UL) {
      count += 1;
    }
  }
  if (op_disc.lower_ & 0x100000UL) {
    if (op_disc.lower_ & 0x8000000UL) {
      if (op_disc.upper_ & 0x4UL) {
        if (op_disc.upper_ & 0x200UL) {
          if (my_disc.upper_ & 0x10000UL) {
            count += 4;
          }
        } else if (my_disc.upper_ & 0x200UL) {
          count += 3;
        }
      } else if (my_disc.upper_ & 0x4UL) {
        count += 2;
      }
    } else if (my_disc.lower_ & 0x8000000UL) {
      count += 1;
    }
  }
  return count;
}

static int g_16(const bit_matrix& my_disc, const bit_matrix& op_disc) {
  int count = 0;
  if (op_disc.lower_ & 0x2000UL) {
    if (op_disc.lower_ & 0x1000UL) {
      if (op_disc.lower_ & 0x800UL) {
        if (op_disc.lower_ & 0x400UL) {
          if (op_disc.lower_ & 0x200UL) {
            if (my_disc.lower_ & 0x100UL) {
              count += 5;
            }
          } else if (my_disc.lower_ & 0x200UL) {
            count += 4;
          }
        } else if (my_disc.lower_ & 0x400UL) {
          count += 3;
        }
      } else if (my_disc.lower_ & 0x800UL) {
        count += 2;
      }
    } else if (my_disc.lower_ & 0x1000UL) {
      count += 1;
    }
  }
  if (op_disc.lower_ & 0x400000UL) {
    if (op_disc.lower_ & 0x40000000UL) {
      if (op_disc.upper_ & 0x40UL) {
        if (op_disc.upper_ & 0x4000UL) {
          if (op_disc.upper_ & 0x400000UL) {
            if (my_disc.upper_ & 0x40000000UL) {
              count += 5;
            }
          } else if (my_disc.upper_ & 0x400000UL) {
            count += 4;
          }
        } else if (my_disc.upper_ & 0x4000UL) {
          count += 3;
        }
      } else if (my_disc.upper_ & 0x40UL) {
        count += 2;
      }
    } else if (my_disc.lower_ & 0x40000000UL) {
      count += 1;
    }
  }
  if (op_disc.lower_ & 0x200000UL) {
    if (op_disc.lower_ & 0x10000000UL) {
      if (op_disc.upper_ & 0x8UL) {
        if (op_disc.upper_ & 0x400UL) {
          if (op_disc.upper_ & 0x20000UL) {
            if (my_disc.upper_ & 0x1000000UL) {
              count += 5;
            }
          } else if (my_disc.upper_ & 0x20000UL) {
            count += 4;
          }
        } else if (my_disc.upper_ & 0x400UL) {
          count += 3;
        }
      } else if (my_disc.upper_ & 0x8UL) {
        count += 2;
      }
    } else if (my_disc.lower_ & 0x10000000UL) {
      count += 1;
    }
  }
  return count;
}

static int g_17(const bit_matrix& my_disc, const bit_matrix& op_disc) {
  int count = 0;
  if (op_disc.lower_ & 0x4000UL) {
    if (op_disc.lower_ & 0x2000UL) {
      if (op_disc.lower_ & 0x1000UL) {
        if (op_disc.lower_ & 0x800UL) {
          if (op_disc.lower_ & 0x400UL) {
            if (op_disc.lower_ & 0x200UL) {
              if (my_disc.lower_ & 0x100UL) {
                count += 6;
              }
            } else if (my_disc.lower_ & 0x200UL) {
              count += 5;
            }
          } else if (my_disc.lower_ & 0x400UL) {
            count += 4;
          }
        } else if (my_disc.lower_ & 0x800UL) {
          count += 3;
        }
      } else if (my_disc.lower_ & 0x1000UL) {
        count += 2;
      }
    } else if (my_disc.lower_ & 0x2000UL) {
      count += 1;
    }
  }
  if (op_disc.lower_ & 0x800000UL) {
    if (op_disc.lower_ & 0x80000000UL) {
      if (op_disc.upper_ & 0x80UL) {
        if (op_disc.upper_ & 0x8000UL) {
          if (op_disc.upper_ & 0x800000UL) {
            if (my_disc.upper_ & 0x80000000UL) {
              count += 5;
            }
          } else if (my_disc.upper_ & 0x800000UL) {
            count += 4;
          }
        } else if (my_disc.upper_ & 0x8000UL) {
          count += 3;
        }
      } else if (my_disc.upper_ & 0x80UL) {
        count += 2;
      }
    } else if (my_disc.lower_ & 0x80000000UL) {
      count += 1;
    }
  }
  if (op_disc.lower_ & 0x400000UL) {
    if (op_disc.lower_ & 0x20000000UL) {
      if (op_disc.upper_ & 0x10UL) {
        if (op_disc.upper_ & 0x800UL) {
          if (op_disc.upper_ & 0x40000UL) {
            if (my_disc.upper_ & 0x2000000UL) {
              count += 5;
            }
          } else if (my_disc.upper_ & 0x40000UL) {
            count += 4;
          }
        } else if (my_disc.upper_ & 0x800UL) {
          count += 3;
        }
      } else if (my_disc.upper_ & 0x10UL) {
        count += 2;
      }
    } else if (my_disc.lower_ & 0x20000000UL) {
      count += 1;
    }
  }
  return count;
}

static int g_20(const bit_matrix& my_disc, const bit_matrix& op_disc) {
  int count = 0;
  if (op_disc.lower_ & 0x20000UL) {
    if (op_disc.lower_ & 0x40000UL) {
      if (op_disc.lower_ & 0x80000UL) {
        if (op_disc.lower_ & 0x100000UL) {
          if (op_disc.lower_ & 0x200000UL) {
            if (op_disc.lower_ & 0x400000UL) {
              if (my_disc.lower_ & 0x800000UL) {
                count += 6;
              }
            } else if (my_disc.lower_ & 0x400000UL) {
              count += 5;
            }
          } else if (my_disc.lower_ & 0x200000UL) {
            count += 4;
          }
        } else if (my_disc.lower_ & 0x100000UL) {
          count += 3;
        }
      } else if (my_disc.lower_ & 0x80000UL) {
        count += 2;
      }
    } else if (my_disc.lower_ & 0x40000UL) {
      count += 1;
    }
  }
  if (op_disc.lower_ & 0x1000000UL) {
    if (op_disc.upper_ & 0x1UL) {
      if (op_disc.upper_ & 0x100UL) {
        if (op_disc.upper_ & 0x10000UL) {
          if (my_disc.upper_ & 0x1000000UL) {
            count += 4;
          }
        } else if (my_disc.upper_ & 0x10000UL) {
          count += 3;
        }
      } else if (my_disc.upper_ & 0x100UL) {
        count += 2;
      }
    } else if (my_disc.upper_ & 0x1UL) {
      count += 1;
    }
  }
  if (op_disc.lower_ & 0x100UL) {
    if (my_disc.lower_ & 0x1UL) {
      count += 1;
    }
  }
  if (op_disc.lower_ & 0x2000000UL) {
    if (op_disc.upper_ & 0x4UL) {
      if (op_disc.upper_ & 0x800UL) {
        if (op_disc.upper_ & 0x100000UL) {
          if (my_disc.upper_ & 0x20000000UL) {
            count += 4;
          }
        } else if (my_disc.upper_ & 0x100000UL) {
          count += 3;
        }
      } else if (my_disc.upper_ & 0x800UL) {
        count += 2;
      }
    } else if (my_disc.upper_ & 0x4UL) {
      count += 1;
    }
  }
  if (op_disc.lower_ & 0x200UL) {
    if (my_disc.lower_ & 0x4UL) {
      count += 1;
    }
  }
  return count;
}

static int g_21(const bit_matrix& my_disc, const bit_matrix& op_disc) {
  int count = 0;
  if (op_disc.lower_ & 0x40000UL) {
    if (op_disc.lower_ & 0x80000UL) {
      if (op_disc.lower_ & 0x100000UL) {
        if (op_disc.lower_ & 0x200000UL) {
          if (op_disc.lower_ & 0x400000UL) {
            if (my_disc.lower_ & 0x800000UL) {
              count += 5;
            }
          } else if (my_disc.lower_ & 0x400000UL) {
            count += 4;
          }
        } else if (my_disc.lower_ & 0x200000UL) {
          count += 3;
        }
      } else if (my_disc.lower_ & 0x100000UL) {
        count += 2;
      }
    } else if (my_disc.lower_ & 0x80000UL) {
      count += 1;
    }
  }
  if (op_disc.lower_ & 0x2000000UL) {
    if (op_disc.upper_ & 0x2UL) {
      if (op_disc.upper_ & 0x200UL) {
        if (op_disc.upper_ & 0x20000UL) {
          if (my_disc.upper_ & 0x2000000UL) {
            count += 4;
          }
        } else if (my_disc.upper_ & 0x20000UL) {
          count += 3;
        }
      } else if (my_disc.upper_ & 0x200UL) {
        count += 2;
      }
    } else if (my_disc.upper_ & 0x2UL) {
      count += 1;
    }
  }
  if (op_disc.lower_ & 0x200UL) {
    if (my_disc.lower_ & 0x2UL) {
      count += 1;
    }
  }
  if (op_disc.lower_ & 0x4000000UL) {
    if (op_disc.upper_ & 0x8UL) {
      if (op_disc.upper_ & 0x1000UL) {
        if (op_disc.upper_ & 0x200000UL) {
          if (my_disc.upper_ & 0x40000000UL) {
            count += 4;
          }
        } else if (my_disc.upper_ & 0x200000UL) {
          count += 3;
        }
      } else if (my_disc.upper_ & 0x1000UL) {
        count += 2;
      }
    } else if (my_disc.upper_ & 0x8UL) {
      count += 1;
    }
  }
  if (op_disc.lower_ & 0x400UL) {
    if (my_disc.lower_ & 0x8UL) {
      count += 1;
    }
  }
  return count;
}

static int g_22(const bit_matrix& my_disc, const bit_matrix& op_disc) {
  int count = 0;
  if (op_disc.lower_ & 0x80000UL) {
    if (op_disc.lower_ & 0x100000UL) {
      if (op_disc.lower_ & 0x200000UL) {
        if (op_disc.lower_ & 0x400000UL) {
          if (my_disc.lower_ & 0x800000UL) {
            count += 4;
          }
        } else if (my_disc.lower_ & 0x400000UL) {
          count += 3;
        }
      } else if (my_disc.lower_ & 0x200000UL) {
        count += 2;
      }
    } else if (my_disc.lower_ & 0x100000UL) {
      count += 1;
    }
  }
  if (op_disc.lower_ & 0x20000UL) {
    if (my_disc.lower_ & 0x10000UL) {
      count += 1;
    }
  }
  if (op_disc.lower_ & 0x4000000UL) {
    if (op_disc.upper_ & 0x4UL) {
      if (op_disc.upper_ & 0x400UL) {
        if (op_disc.upper_ & 0x40000UL) {
          if (my_disc.upper_ & 0x4000000UL) {
            count += 4;
          }
        } else if (my_disc.upper_ & 0x40000UL) {
          count += 3;
        }
      } else if (my_disc.upper_ & 0x400UL) {
        count += 2;
      }
    } else if (my_disc.upper_ & 0x4UL) {
      count += 1;
    }
  }
  if (op_disc.lower_ & 0x400UL) {
    if (my_disc.lower_ & 0x4UL) {
      count += 1;
    }
  }
  if (op_disc.lower_ & 0x8000000UL) {
    if (op_disc.upper_ & 0x10UL) {
      if (op_disc.upper_ & 0x2000UL) {
        if (op_disc.upper_ & 0x400000UL) {
          if (my_disc.upper_ & 0x80000000UL) {
            count += 4;
          }
        } else if (my_disc.upper_ & 0x400000UL) {
          count += 3;
        }
      } else if (my_disc.upper_ & 0x2000UL) {
        count += 2;
      }
    } else if (my_disc.upper_ & 0x10UL) {
      count += 1;
    }
  }
  if (op_disc.lower_ & 0x800UL) {
    if (my_disc.lower_ & 0x10UL) {
      count += 1;
    }
  }
  if (op_disc.lower_ & 0x2000000UL) {
    if (my_disc.upper_ & 0x1UL) {
      count += 1;
    }
  }
  if (op_disc.lower_ & 0x200UL) {
    if (my_disc.lower_ & 0x1UL) {
      count += 1;
    }
  }
  return count;
}

static int g_23(const bit_matrix& my_disc, const bit_matrix& op_disc) {
  int count = 0;
  if (op_disc.lower_ & 0x100000UL) {
    if (op_disc.lower_ & 0x200000UL) {
      if (op_disc.lower_ & 0x400000UL) {
        if (my_disc.lower_ & 0x800000UL) {
          count += 3;
        }
      } else if (my_disc.lower_ & 0x400000UL) {
        count += 2;
      }
    } else if (my_disc.lower_ & 0x200000UL) {
      count += 1;
    }
  }
  if (op_disc.lower_ & 0x40000UL) {
    if (op_disc.lower_ & 0x20000UL) {
      if (my_disc.lower_ & 0x10000UL) {
        count += 2;
      }
    } else if (my_disc.lower_ & 0x20000UL) {
      count += 1;
    }
  }
  if (op_disc.lower_ & 0x8000000UL) {
    if (op_disc.upper_ & 0x8UL) {
      if (op_disc.upper_ & 0x800UL) {
        if (op_disc.upper_ & 0x80000UL) {
          if (my_disc.upper_ & 0x8000000UL) {
            count += 4;
          }
        } else if (my_disc.upper_ & 0x80000UL) {
          count += 3;
        }
      } else if (my_disc.upper_ & 0x800UL) {
        count += 2;
      }
    } else if (my_disc.upper_ & 0x8UL) {
      count += 1;
    }
  }
  if (op_disc.lower_ & 0x800UL) {
    if (my_disc.lower_ & 0x8UL) {
      count += 1;
    }
  }
  if (op_disc.lower_ & 0x10000000UL) {
    if (op_disc.upper_ & 0x20UL) {
      if (op_disc.upper_ & 0x4000UL) {
        if (my_disc.upper_ & 0x800000UL) {
          count += 3;
        }
      } else if (my_disc.upper_ & 0x4000UL) {
        count += 2;
      }
    } else if (my_disc.upper_ & 0x20UL) {
      count += 1;
    }
  }
  if (op_disc.lower_ & 0x1000UL) {
    if (my_disc.lower_ & 0x20UL) {
      count += 1;
    }
  }
  if (op_disc.lower_ & 0x4000000UL) {
    if (op_disc.upper_ & 0x2UL) {
      if (my_disc.upper_ & 0x100UL) {
        count += 2;
      }
    } else if (my_disc.upper_ & 0x2UL) {
      count += 1;
    }
  }
  if (op_disc.lower_ & 0x400UL) {
    if (my_disc.lower_ & 0x2UL) {
      count += 1;
    }
  }
  return count;
}

static int g_24(const bit_matrix& my_disc, const bit_matrix& op_disc) {
  int count = 0;
  if (op_disc.lower_ & 0x200000UL) {
    if (op_disc.lower_ & 0x400000UL) {
      if (my_disc.lower_ & 0x800000UL) {
        count += 2;
      }
    } else if (my_disc.lower_ & 0x400000UL) {
      count += 1;
    }
  }
  if (op_disc.lower_ & 0x80000UL) {
    if (op_disc.lower_ & 0x40000UL) {
      if (op_disc.lower_ & 0x20000UL) {
        if (my_disc.lower_ & 0x10000UL) {
          count += 3;
        }
      } else if (my_disc.lower_ & 0x20000UL) {
        count += 2;
      }
    } else if (my_disc.lower_ & 0x40000UL) {
      count += 1;
    }
  }
  if (op_disc.lower_ & 0x10000000UL) {
    if (op_disc.upper_ & 0x10UL) {
      if (op_disc.upper_ & 0x1000UL) {
        if (op_disc.upper_ & 0x100000UL) {
          if (my_disc.upper_ & 0x10000000UL) {
            count += 4;
          }
        } else if (my_disc.upper_ & 0x100000UL) {
          count += 3;
        }
      } else if (my_disc.upper_ & 0x1000UL) {
        count += 2;
      }
    } else if (my_disc.upper_ & 0x10UL) {
      count += 1;
    }
  }
  if (op_disc.lower_ & 0x1000UL) {
    if (my_disc.lower_ & 0x10UL) {
      count += 1;
    }
  }
  if (op_disc.lower_ & 0x20000000UL) {
    if (op_disc.upper_ & 0x40UL) {
      if (my_disc.upper_ & 0x8000UL) {
        count += 2;
      }
    } else if (my_disc.upper_ & 0x40UL) {
      count += 1;
    }
  }
  if (op_disc.lower_ & 0x2000UL) {
    if (my_disc.lower_ & 0x40UL) {
      count += 1;
    }
  }
  if (op_disc.lower_ & 0x8000000UL) {
    if (op_disc.upper_ & 0x4UL) {
      if (op_disc.upper_ & 0x200UL) {
        if (my_disc.upper_ & 0x10000UL) {
          count += 3;
        }
      } else if (my_disc.upper_ & 0x200UL) {
        count += 2;
      }
    } else if (my_disc.upper_ & 0x4UL) {
      count += 1;
    }
  }
  if (op_disc.lower_ & 0x800UL) {
    if (my_disc.lower_ & 0x4UL) {
      count += 1;
    }
  }
  return count;
}

static int g_25(const bit_matrix& my_disc, const bit_matrix& op_disc) {
  int count = 0;
  if (op_disc.lower_ & 0x400000UL) {
    if (my_disc.lower_ & 0x800000UL) {
      count += 1;
    }
  }
  if (op_disc.lower_ & 0x100000UL) {
    if (op_disc.lower_ & 0x80000UL) {
      if (op_disc.lower_ & 0x40000UL) {
        if (op_disc.lower_ & 0x20000UL) {
          if (my_disc.lower_ & 0x10000UL) {
            count += 4;
          }
        } else if (my_disc.lower_ & 0x20000UL) {
          count += 3;
        }
      } else if (my_disc.lower_ & 0x40000UL) {
        count += 2;
      }
    } else if (my_disc.lower_ & 0x80000UL) {
      count += 1;
    }
  }
  if (op_disc.lower_ & 0x20000000UL) {
    if (op_disc.upper_ & 0x20UL) {
      if (op_disc.upper_ & 0x2000UL) {
        if (op_disc.upper_ & 0x200000UL) {
          if (my_disc.upper_ & 0x20000000UL) {
            count += 4;
          }
        } else if (my_disc.upper_ & 0x200000UL) {
          count += 3;
        }
      } else if (my_disc.upper_ & 0x2000UL) {
        count += 2;
      }
    } else if (my_disc.upper_ & 0x20UL) {
      count += 1;
    }
  }
  if (op_disc.lower_ & 0x2000UL) {
    if (my_disc.lower_ & 0x20UL) {
      count += 1;
    }
  }
  if (op_disc.lower_ & 0x40000000UL) {
    if (my_disc.upper_ & 0x80UL) {
      count += 1;
    }
  }
  if (op_disc.lower_ & 0x4000UL) {
    if (my_disc.lower_ & 0x80UL) {
      count += 1;
    }
  }
  if (op_disc.lower_ & 0x10000000UL) {
    if (op_disc.upper_ & 0x8UL) {
      if (op_disc.upper_ & 0x400UL) {
        if (op_disc.upper_ & 0x20000UL) {
          if (my_disc.upper_ & 0x1000000UL) {
            count += 4;
          }
        } else if (my_disc.upper_ & 0x20000UL) {
          count += 3;
        }
      } else if (my_disc.upper_ & 0x400UL) {
        count += 2;
      }
    } else if (my_disc.upper_ & 0x8UL) {
      count += 1;
    }
  }
  if (op_disc.lower_ & 0x1000UL) {
    if (my_disc.lower_ & 0x8UL) {
      count += 1;
    }
  }
  return count;
}

static int g_26(const bit_matrix& my_disc, const bit_matrix& op_disc) {
  int count = 0;
  if (op_disc.lower_ & 0x200000UL) {
    if (op_disc.lower_ & 0x100000UL) {
      if (op_disc.lower_ & 0x80000UL) {
        if (op_disc.lower_ & 0x40000UL) {
          if (op_disc.lower_ & 0x20000UL) {
            if (my_disc.lower_ & 0x10000UL) {
              count += 5;
            }
          } else if (my_disc.lower_ & 0x20000UL) {
            count += 4;
          }
        } else if (my_disc.lower_ & 0x40000UL) {
          count += 3;
        }
      } else if (my_disc.lower_ & 0x80000UL) {
        count += 2;
      }
    } else if (my_disc.lower_ & 0x100000UL) {
      count += 1;
    }
  }
  if (op_disc.lower_ & 0x40000000UL) {
    if (op_disc.upper_ & 0x40UL) {
      if (op_disc.upper_ & 0x4000UL) {
        if (op_disc.upper_ & 0x400000UL) {
          if (my_disc.upper_ & 0x40000000UL) {
            count += 4;
          }
        } else if (my_disc.upper_ & 0x400000UL) {
          count += 3;
        }
      } else if (my_disc.upper_ & 0x4000UL) {
        count += 2;
      }
    } else if (my_disc.upper_ & 0x40UL) {
      count += 1;
    }
  }
  if (op_disc.lower_ & 0x4000UL) {
    if (my_disc.lower_ & 0x40UL) {
      count += 1;
    }
  }
  if (op_disc.lower_ & 0x20000000UL) {
    if (op_disc.upper_ & 0x10UL) {
      if (op_disc.upper_ & 0x800UL) {
        if (op_disc.upper_ & 0x40000UL) {
          if (my_disc.upper_ & 0x2000000UL) {
            count += 4;
          }
        } else if (my_disc.upper_ & 0x40000UL) {
          count += 3;
        }
      } else if (my_disc.upper_ & 0x800UL) {
        count += 2;
      }
    } else if (my_disc.upper_ & 0x10UL) {
      count += 1;
    }
  }
  if (op_disc.lower_ & 0x2000UL) {
    if (my_disc.lower_ & 0x10UL) {
      count += 1;
    }
  }
  return count;
}

static int g_27(const bit_matrix& my_disc, const bit_matrix& op_disc) {
  int count = 0;
  if (op_disc.lower_ & 0x400000UL) {
    if (op_disc.lower_ & 0x200000UL) {
      if (op_disc.lower_ & 0x100000UL) {
        if (op_disc.lower_ & 0x80000UL) {
          if (op_disc.lower_ & 0x40000UL) {
            if (op_disc.lower_ & 0x20000UL) {
              if (my_disc.lower_ & 0x10000UL) {
                count += 6;
              }
            } else if (my_disc.lower_ & 0x20000UL) {
              count += 5;
            }
          } else if (my_disc.lower_ & 0x40000UL) {
            count += 4;
          }
        } else if (my_disc.lower_ & 0x80000UL) {
          count += 3;
        }
      } else if (my_disc.lower_ & 0x100000UL) {
        count += 2;
      }
    } else if (my_disc.lower_ & 0x200000UL) {
      count += 1;
    }
  }
  if (op_disc.lower_ & 0x80000000UL) {
    if (op_disc.upper_ & 0x80UL) {
      if (op_disc.upper_ & 0x8000UL) {
        if (op_disc.upper_ & 0x800000UL) {
          if (my_disc.upper_ & 0x80000000UL) {
            count += 4;
          }
        } else if (my_disc.upper_ & 0x800000UL) {
          count += 3;
        }
      } else if (my_disc.upper_ & 0x8000UL) {
        count += 2;
      }
    } else if (my_disc.upper_ & 0x80UL) {
      count += 1;
    }
  }
  if (op_disc.lower_ & 0x8000UL) {
    if (my_disc.lower_ & 0x80UL) {
      count += 1;
    }
  }
  if (op_disc.lower_ & 0x40000000UL) {
    if (op_disc.upper_ & 0x20UL) {
      if (op_disc.upper_ & 0x1000UL) {
        if (op_disc.upper_ & 0x80000UL) {
          if (my_disc.upper_ & 0x4000000UL) {
            count += 4;
          }
        } else if (my_disc.upper_ & 0x80000UL) {
          count += 3;
        }
      } else if (my_disc.upper_ & 0x1000UL) {
        count += 2;
      }
    } else if (my_disc.upper_ & 0x20UL) {
      count += 1;
    }
  }
  if (op_disc.lower_ & 0x4000UL) {
    if (my_disc.lower_ & 0x20UL) {
      count += 1;
    }
  }
  return count;
}

static int g_30(const bit_matrix& my_disc, const bit_matrix& op_disc) {
  int count = 0;
  if (op_disc.lower_ & 0x2000000UL) {
    if (op_disc.lower_ & 0x4000000UL) {
      if (op_disc.lower_ & 0x8000000UL) {
        if (op_disc.lower_ & 0x10000000UL) {
          if (op_disc.lower_ & 0x20000000UL) {
            if (op_disc.lower_ & 0x40000000UL) {
              if (my_disc.lower_ & 0x80000000UL) {
                count += 6;
              }
            } else if (my_disc.lower_ & 0x40000000UL) {
              count += 5;
            }
          } else if (my_disc.lower_ & 0x20000000UL) {
            count += 4;
          }
        } else if (my_disc.lower_ & 0x10000000UL) {
          count += 3;
        }
      } else if (my_disc.lower_ & 0x8000000UL) {
        count += 2;
      }
    } else if (my_disc.lower_ & 0x4000000UL) {
      count += 1;
    }
  }
  if (op_disc.upper_ & 0x1UL) {
    if (op_disc.upper_ & 0x100UL) {
      if (op_disc.upper_ & 0x10000UL) {
        if (my_disc.upper_ & 0x1000000UL) {
          count += 3;
        }
      } else if (my_disc.upper_ & 0x10000UL) {
        count += 2;
      }
    } else if (my_disc.upper_ & 0x100UL) {
      count += 1;
    }
  }
  if (op_disc.lower_ & 0x10000UL) {
    if (op_disc.lower_ & 0x100UL) {
      if (my_disc.lower_ & 0x1UL) {
        count += 2;
      }
    } else if (my_disc.lower_ & 0x100UL) {
      count += 1;
    }
  }
  if (op_disc.upper_ & 0x2UL) {
    if (op_disc.upper_ & 0x400UL) {
      if (op_disc.upper_ & 0x80000UL) {
        if (my_disc.upper_ & 0x10000000UL) {
          count += 3;
        }
      } else if (my_disc.upper_ & 0x80000UL) {
        count += 2;
      }
    } else if (my_disc.upper_ & 0x400UL) {
      count += 1;
    }
  }
  if (op_disc.lower_ & 0x20000UL) {
    if (op_disc.lower_ & 0x400UL) {
      if (my_disc.lower_ & 0x8UL) {
        count += 2;
      }
    } else if (my_disc.lower_ & 0x400UL) {
      count += 1;
    }
  }
  return count;
}

static int g_31(const bit_matrix& my_disc, const bit_matrix& op_disc) {
  int count = 0;
  if (op_disc.lower_ & 0x4000000UL) {
    if (op_disc.lower_ & 0x8000000UL) {
      if (op_disc.lower_ & 0x10000000UL) {
        if (op_disc.lower_ & 0x20000000UL) {
          if (op_disc.lower_ & 0x40000000UL) {
            if (my_disc.lower_ & 0x80000000UL) {
              count += 5;
            }
          } else if (my_disc.lower_ & 0x40000000UL) {
            count += 4;
          }
        } else if (my_disc.lower_ & 0x20000000UL) {
          count += 3;
        }
      } else if (my_disc.lower_ & 0x10000000UL) {
        count += 2;
      }
    } else if (my_disc.lower_ & 0x8000000UL) {
      count += 1;
    }
  }
  if (op_disc.upper_ & 0x2UL) {
    if (op_disc.upper_ & 0x200UL) {
      if (op_disc.upper_ & 0x20000UL) {
        if (my_disc.upper_ & 0x2000000UL) {
          count += 3;
        }
      } else if (my_disc.upper_ & 0x20000UL) {
        count += 2;
      }
    } else if (my_disc.upper_ & 0x200UL) {
      count += 1;
    }
  }
  if (op_disc.lower_ & 0x20000UL) {
    if (op_disc.lower_ & 0x200UL) {
      if (my_disc.lower_ & 0x2UL) {
        count += 2;
      }
    } else if (my_disc.lower_ & 0x200UL) {
      count += 1;
    }
  }
  if (op_disc.upper_ & 0x4UL) {
    if (op_disc.upper_ & 0x800UL) {
      if (op_disc.upper_ & 0x100000UL) {
        if (my_disc.upper_ & 0x20000000UL) {
          count += 3;
        }
      } else if (my_disc.upper_ & 0x100000UL) {
        count += 2;
      }
    } else if (my_disc.upper_ & 0x800UL) {
      count += 1;
    }
  }
  if (op_disc.lower_ & 0x40000UL) {
    if (op_disc.lower_ & 0x800UL) {
      if (my_disc.lower_ & 0x10UL) {
        count += 2;
      }
    } else if (my_disc.lower_ & 0x800UL) {
      count += 1;
    }
  }
  return count;
}

static int g_32(const bit_matrix& my_disc, const bit_matrix& op_disc) {
  int count = 0;
  if (op_disc.lower_ & 0x8000000UL) {
    if (op_disc.lower_ & 0x10000000UL) {
      if (op_disc.lower_ & 0x20000000UL) {
        if (op_disc.lower_ & 0x40000000UL) {
          if (my_disc.lower_ & 0x80000000UL) {
            count += 4;
          }
        } else if (my_disc.lower_ & 0x40000000UL) {
          count += 3;
        }
      } else if (my_disc.lower_ & 0x20000000UL) {
        count += 2;
      }
    } else if (my_disc.lower_ & 0x10000000UL) {
      count += 1;
    }
  }
  if (op_disc.lower_ & 0x2000000UL) {
    if (my_disc.lower_ & 0x1000000UL) {
      count += 1;
    }
  }
  if (op_disc.upper_ & 0x4UL) {
    if (op_disc.upper_ & 0x400UL) {
      if (op_disc.upper_ & 0x40000UL) {
        if (my_disc.upper_ & 0x4000000UL) {
          count += 3;
        }
      } else if (my_disc.upper_ & 0x40000UL) {
        count += 2;
      }
    } else if (my_disc.upper_ & 0x400UL) {
      count += 1;
    }
  }
  if (op_disc.lower_ & 0x40000UL) {
    if (op_disc.lower_ & 0x400UL) {
      if (my_disc.lower_ & 0x4UL) {
        count += 2;
      }
    } else if (my_disc.lower_ & 0x400UL) {
      count += 1;
    }
  }
  if (op_disc.upper_ & 0x8UL) {
    if (op_disc.upper_ & 0x1000UL) {
      if (op_disc.upper_ & 0x200000UL) {
        if (my_disc.upper_ & 0x40000000UL) {
          count += 3;
        }
      } else if (my_disc.upper_ & 0x200000UL) {
        count += 2;
      }
    } else if (my_disc.upper_ & 0x1000UL) {
      count += 1;
    }
  }
  if (op_disc.lower_ & 0x80000UL) {
    if (op_disc.lower_ & 0x1000UL) {
      if (my_disc.lower_ & 0x20UL) {
        count += 2;
      }
    } else if (my_disc.lower_ & 0x1000UL) {
      count += 1;
    }
  }
  if (op_disc.upper_ & 0x2UL) {
    if (my_disc.upper_ & 0x100UL) {
      count += 1;
    }
  }
  if (op_disc.lower_ & 0x20000UL) {
    if (my_disc.lower_ & 0x100UL) {
      count += 1;
    }
  }
  return count;
}

static int g_33(const bit_matrix& my_disc, const bit_matrix& op_disc) {
  int count = 0;
  if (op_disc.lower_ & 0x10000000UL) {
    if (op_disc.lower_ & 0x20000000UL) {
      if (op_disc.lower_ & 0x40000000UL) {
        if (my_disc.lower_ & 0x80000000UL) {
          count += 3;
        }
      } else if (my_disc.lower_ & 0x40000000UL) {
        count += 2;
      }
    } else if (my_disc.lower_ & 0x20000000UL) {
      count += 1;
    }
  }
  if (op_disc.lower_ & 0x4000000UL) {
    if (op_disc.lower_ & 0x2000000UL) {
      if (my_disc.lower_ & 0x1000000UL) {
        count += 2;
      }
    } else if (my_disc.lower_ & 0x2000000UL) {
      count += 1;
    }
  }
  if (op_disc.upper_ & 0x8UL) {
    if (op_disc.upper_ & 0x800UL) {
      if (op_disc.upper_ & 0x80000UL) {
        if (my_disc.upper_ & 0x8000000UL) {
          count += 3;
        }
      } else if (my_disc.upper_ & 0x80000UL) {
        count += 2;
      }
    } else if (my_disc.upper_ & 0x800UL) {
      count += 1;
    }
  }
  if (op_disc.lower_ & 0x80000UL) {
    if (op_disc.lower_ & 0x800UL) {
      if (my_disc.lower_ & 0x8UL) {
        count += 2;
      }
    } else if (my_disc.lower_ & 0x800UL) {
      count += 1;
    }
  }
  if (op_disc.upper_ & 0x10UL) {
    if (op_disc.upper_ & 0x2000UL) {
      if (op_disc.upper_ & 0x400000UL) {
        if (my_disc.upper_ & 0x80000000UL) {
          count += 3;
        }
      } else if (my_disc.upper_ & 0x400000UL) {
        count += 2;
      }
    } else if (my_disc.upper_ & 0x2000UL) {
      count += 1;
    }
  }
  if (op_disc.lower_ & 0x100000UL) {
    if (op_disc.lower_ & 0x2000UL) {
      if (my_disc.lower_ & 0x40UL) {
        count += 2;
      }
    } else if (my_disc.lower_ & 0x2000UL) {
      count += 1;
    }
  }
  if (op_disc.upper_ & 0x4UL) {
    if (op_disc.upper_ & 0x200UL) {
      if (my_disc.upper_ & 0x10000UL) {
        count += 2;
      }
    } else if (my_disc.upper_ & 0x200UL) {
      count += 1;
    }
  }
  if (op_disc.lower_ & 0x40000UL) {
    if (op_disc.lower_ & 0x200UL) {
      if (my_disc.lower_ & 0x1UL) {
        count += 2;
      }
    } else if (my_disc.lower_ & 0x200UL) {
      count += 1;
    }
  }
  return count;
}

static int g_34(const bit_matrix& my_disc, const bit_matrix& op_disc) {
  int count = 0;
  if (op_disc.lower_ & 0x20000000UL) {
    if (op_disc.lower_ & 0x40000000UL) {
      if (my_disc.lower_ & 0x80000000UL) {
        count += 2;
      }
    } else if (my_disc.lower_ & 0x40000000UL) {
      count += 1;
    }
  }
  if (op_disc.lower_ & 0x8000000UL) {
    if (op_disc.lower_ & 0x4000000UL) {
      if (op_disc.lower_ & 0x2000000UL) {
        if (my_disc.lower_ & 0x1000000UL) {
          count += 3;
        }
      } else if (my_disc.lower_ & 0x2000000UL) {
        count += 2;
      }
    } else if (my_disc.lower_ & 0x4000000UL) {
      count += 1;
    }
  }
  if (op_disc.upper_ & 0x10UL) {
    if (op_disc.upper_ & 0x1000UL) {
      if (op_disc.upper_ & 0x100000UL) {
        if (my_disc.upper_ & 0x10000000UL) {
          count += 3;
        }
      } else if (my_disc.upper_ & 0x100000UL) {
        count += 2;
      }
    } else if (my_disc.upper_ & 0x1000UL) {
      count += 1;
    }
  }
  if (op_disc.lower_ & 0x100000UL) {
    if (op_disc.lower_ & 0x1000UL) {
      if (my_disc.lower_ & 0x10UL) {
        count += 2;
      }
    } else if (my_disc.lower_ & 0x1000UL) {
      count += 1;
    }
  }
  if (op_disc.upper_ & 0x20UL) {
    if (op_disc.upper_ & 0x4000UL) {
      if (my_disc.upper_ & 0x800000UL) {
        count += 2;
      }
    } else if (my_disc.upper_ & 0x4000UL) {
      count += 1;
    }
  }
  if (op_disc.lower_ & 0x200000UL) {
    if (op_disc.lower_ & 0x4000UL) {
      if (my_disc.lower_ & 0x80UL) {
        count += 2;
      }
    } else if (my_disc.lower_ & 0x4000UL) {
      count += 1;
    }
  }
  if (op_disc.upper_ & 0x8UL) {
    if (op_disc.upper_ & 0x400UL) {
      if (op_disc.upper_ & 0x20000UL) {
        if (my_disc.upper_ & 0x1000000UL) {
          count += 3;
        }
      } else if (my_disc.upper_ & 0x20000UL) {
        count += 2;
      }
    } else if (my_disc.upper_ & 0x400UL) {
      count += 1;
    }
  }
  if (op_disc.lower_ & 0x80000UL) {
    if (op_disc.lower_ & 0x400UL) {
      if (my_disc.lower_ & 0x2UL) {
        count += 2;
      }
    } else if (my_disc.lower_ & 0x400UL) {
      count += 1;
    }
  }
  return count;
}

static int g_35(const bit_matrix& my_disc, const bit_matrix& op_disc) {
  int count = 0;
  if (op_disc.lower_ & 0x40000000UL) {
    if (my_disc.lower_ & 0x80000000UL) {
      count += 1;
    }
  }
  if (op_disc.lower_ & 0x10000000UL) {
    if (op_disc.lower_ & 0x8000000UL) {
      if (op_disc.lower_ & 0x4000000UL) {
        if (op_disc.lower_ & 0x2000000UL) {
          if (my_disc.lower_ & 0x1000000UL) {
            count += 4;
          }
        } else if (my_disc.lower_ & 0x2000000UL) {
          count += 3;
        }
      } else if (my_disc.lower_ & 0x4000000UL) {
        count += 2;
      }
    } else if (my_disc.lower_ & 0x8000000UL) {
      count += 1;
    }
  }
  if (op_disc.upper_ & 0x20UL) {
    if (op_disc.upper_ & 0x2000UL) {
      if (op_disc.upper_ & 0x200000UL) {
        if (my_disc.upper_ & 0x20000000UL) {
          count += 3;
        }
      } else if (my_disc.upper_ & 0x200000UL) {
        count += 2;
      }
    } else if (my_disc.upper_ & 0x2000UL) {
      count += 1;
    }
  }
  if (op_disc.lower_ & 0x200000UL) {
    if (op_disc.lower_ & 0x2000UL) {
      if (my_disc.lower_ & 0x20UL) {
        count += 2;
      }
    } else if (my_disc.lower_ & 0x2000UL) {
      count += 1;
    }
  }
  if (op_disc.upper_ & 0x40UL) {
    if (my_disc.upper_ & 0x8000UL) {
      count += 1;
    }
  }
  if (op_disc.lower_ & 0x400000UL) {
    if (my_disc.lower_ & 0x8000UL) {
      count += 1;
    }
  }
  if (op_disc.upper_ & 0x10UL) {
    if (op_disc.upper_ & 0x800UL) {
      if (op_disc.upper_ & 0x40000UL) {
        if (my_disc.upper_ & 0x2000000UL) {
          count += 3;
        }
      } else if (my_disc.upper_ & 0x40000UL) {
        count += 2;
      }
    } else if (my_disc.upper_ & 0x800UL) {
      count += 1;
    }
  }
  if (op_disc.lower_ & 0x100000UL) {
    if (op_disc.lower_ & 0x800UL) {
      if (my_disc.lower_ & 0x4UL) {
        count += 2;
      }
    } else if (my_disc.lower_ & 0x800UL) {
      count += 1;
    }
  }
  return count;
}

static int g_36(const bit_matrix& my_disc, const bit_matrix& op_disc) {
  int count = 0;
  if (op_disc.lower_ & 0x20000000UL) {
    if (op_disc.lower_ & 0x10000000UL) {
      if (op_disc.lower_ & 0x8000000UL) {
        if (op_disc.lower_ & 0x4000000UL) {
          if (op_disc.lower_ & 0x2000000UL) {
            if (my_disc.lower_ & 0x1000000UL) {
              count += 5;
            }
          } else if (my_disc.lower_ & 0x2000000UL) {
            count += 4;
          }
        } else if (my_disc.lower_ & 0x4000000UL) {
          count += 3;
        }
      } else if (my_disc.lower_ & 0x8000000UL) {
        count += 2;
      }
    } else if (my_disc.lower_ & 0x10000000UL) {
      count += 1;
    }
  }
  if (op_disc.upper_ & 0x40UL) {
    if (op_disc.upper_ & 0x4000UL) {
      if (op_disc.upper_ & 0x400000UL) {
        if (my_disc.upper_ & 0x40000000UL) {
          count += 3;
        }
      } else if (my_disc.upper_ & 0x400000UL) {
        count += 2;
      }
    } else if (my_disc.upper_ & 0x4000UL) {
      count += 1;
    }
  }
  if (op_disc.lower_ & 0x400000UL) {
    if (op_disc.lower_ & 0x4000UL) {
      if (my_disc.lower_ & 0x40UL) {
        count += 2;
      }
    } else if (my_disc.lower_ & 0x4000UL) {
      count += 1;
    }
  }
  if (op_disc.upper_ & 0x20UL) {
    if (op_disc.upper_ & 0x1000UL) {
      if (op_disc.upper_ & 0x80000UL) {
        if (my_disc.upper_ & 0x4000000UL) {
          count += 3;
        }
      } else if (my_disc.upper_ & 0x80000UL) {
        count += 2;
      }
    } else if (my_disc.upper_ & 0x1000UL) {
      count += 1;
    }
  }
  if (op_disc.lower_ & 0x200000UL) {
    if (op_disc.lower_ & 0x1000UL) {
      if (my_disc.lower_ & 0x8UL) {
        count += 2;
      }
    } else if (my_disc.lower_ & 0x1000UL) {
      count += 1;
    }
  }
  return count;
}

static int g_37(const bit_matrix& my_disc, const bit_matrix& op_disc) {
  int count = 0;
  if (op_disc.lower_ & 0x40000000UL) {
    if (op_disc.lower_ & 0x20000000UL) {
      if (op_disc.lower_ & 0x10000000UL) {
        if (op_disc.lower_ & 0x8000000UL) {
          if (op_disc.lower_ & 0x4000000UL) {
            if (op_disc.lower_ & 0x2000000UL) {
              if (my_disc.lower_ & 0x1000000UL) {
                count += 6;
              }
            } else if (my_disc.lower_ & 0x2000000UL) {
              count += 5;
            }
          } else if (my_disc.lower_ & 0x4000000UL) {
            count += 4;
          }
        } else if (my_disc.lower_ & 0x8000000UL) {
          count += 3;
        }
      } else if (my_disc.lower_ & 0x10000000UL) {
        count += 2;
      }
    } else if (my_disc.lower_ & 0x20000000UL) {
      count += 1;
    }
  }
  if (op_disc.upper_ & 0x80UL) {
    if (op_disc.upper_ & 0x8000UL) {
      if (op_disc.upper_ & 0x800000UL) {
        if (my_disc.upper_ & 0x80000000UL) {
          count += 3;
        }
      } else if (my_disc.upper_ & 0x800000UL) {
        count += 2;
      }
    } else if (my_disc.upper_ & 0x8000UL) {
      count += 1;
    }
  }
  if (op_disc.lower_ & 0x800000UL) {
    if (op_disc.lower_ & 0x8000UL) {
      if (my_disc.lower_ & 0x80UL) {
        count += 2;
      }
    } else if (my_disc.lower_ & 0x8000UL) {
      count += 1;
    }
  }
  if (op_disc.upper_ & 0x40UL) {
    if (op_disc.upper_ & 0x2000UL) {
      if (op_disc.upper_ & 0x100000UL) {
        if (my_disc.upper_ & 0x8000000UL) {
          count += 3;
        }
      } else if (my_disc.upper_ & 0x100000UL) {
        count += 2;
      }
    } else if (my_disc.upper_ & 0x2000UL) {
      count += 1;
    }
  }
  if (op_disc.lower_ & 0x400000UL) {
    if (op_disc.lower_ & 0x2000UL) {
      if (my_disc.lower_ & 0x10UL) {
        count += 2;
      }
    } else if (my_disc.lower_ & 0x2000UL) {
      count += 1;
    }
  }
  return count;
}

static int g_40(const bit_matrix& my_disc, const bit_matrix& op_disc) {
  int count = 0;
  if (op_disc.upper_ & 0x2UL) {
    if (op_disc.upper_ & 0x4UL) {
      if (op_disc.upper_ & 0x8UL) {
        if (op_disc.upper_ & 0x10UL) {
          if (op_disc.upper_ & 0x20UL) {
            if (op_disc.upper_ & 0x40UL) {
              if (my_disc.upper_ & 0x80UL) {
                count += 6;
              }
            } else if (my_disc.upper_ & 0x40UL) {
              count += 5;
            }
          } else if (my_disc.upper_ & 0x20UL) {
            count += 4;
          }
        } else if (my_disc.upper_ & 0x10UL) {
          count += 3;
        }
      } else if (my_disc.upper_ & 0x8UL) {
        count += 2;
      }
    } else if (my_disc.upper_ & 0x4UL) {
      count += 1;
    }
  }
  if (op_disc.upper_ & 0x100UL) {
    if (op_disc.upper_ & 0x10000UL) {
      if (my_disc.upper_ & 0x1000000UL) {
        count += 2;
      }
    } else if (my_disc.upper_ & 0x10000UL) {
      count += 1;
    }
  }
  if (op_disc.lower_ & 0x1000000UL) {
    if (op_disc.lower_ & 0x10000UL) {
      if (op_disc.lower_ & 0x100UL) {
        if (my_disc.lower_ & 0x1UL) {
          count += 3;
        }
      } else if (my_disc.lower_ & 0x100UL) {
        count += 2;
      }
    } else if (my_disc.lower_ & 0x10000UL) {
      count += 1;
    }
  }
  if (op_disc.upper_ & 0x200UL) {
    if (op_disc.upper_ & 0x40000UL) {
      if (my_disc.upper_ & 0x8000000UL) {
        count += 2;
      }
    } else if (my_disc.upper_ & 0x40000UL) {
      count += 1;
    }
  }
  if (op_disc.lower_ & 0x2000000UL) {
    if (op_disc.lower_ & 0x40000UL) {
      if (op_disc.lower_ & 0x800UL) {
        if (my_disc.lower_ & 0x10UL) {
          count += 3;
        }
      } else if (my_disc.lower_ & 0x800UL) {
        count += 2;
      }
    } else if (my_disc.lower_ & 0x40000UL) {
      count += 1;
    }
  }
  return count;
}

static int g_41(const bit_matrix& my_disc, const bit_matrix& op_disc) {
  int count = 0;
  if (op_disc.upper_ & 0x4UL) {
    if (op_disc.upper_ & 0x8UL) {
      if (op_disc.upper_ & 0x10UL) {
        if (op_disc.upper_ & 0x20UL) {
          if (op_disc.upper_ & 0x40UL) {
            if (my_disc.upper_ & 0x80UL) {
              count += 5;
            }
          } else if (my_disc.upper_ & 0x40UL) {
            count += 4;
          }
        } else if (my_disc.upper_ & 0x20UL) {
          count += 3;
        }
      } else if (my_disc.upper_ & 0x10UL) {
        count += 2;
      }
    } else if (my_disc.upper_ & 0x8UL) {
      count += 1;
    }
  }
  if (op_disc.upper_ & 0x200UL) {
    if (op_disc.upper_ & 0x20000UL) {
      if (my_disc.upper_ & 0x2000000UL) {
        count += 2;
      }
    } else if (my_disc.upper_ & 0x20000UL) {
      count += 1;
    }
  }
  if (op_disc.lower_ & 0x2000000UL) {
    if (op_disc.lower_ & 0x20000UL) {
      if (op_disc.lower_ & 0x200UL) {
        if (my_disc.lower_ & 0x2UL) {
          count += 3;
        }
      } else if (my_disc.lower_ & 0x200UL) {
        count += 2;
      }
    } else if (my_disc.lower_ & 0x20000UL) {
      count += 1;
    }
  }
  if (op_disc.upper_ & 0x400UL) {
    if (op_disc.upper_ & 0x80000UL) {
      if (my_disc.upper_ & 0x10000000UL) {
        count += 2;
      }
    } else if (my_disc.upper_ & 0x80000UL) {
      count += 1;
    }
  }
  if (op_disc.lower_ & 0x4000000UL) {
    if (op_disc.lower_ & 0x80000UL) {
      if (op_disc.lower_ & 0x1000UL) {
        if (my_disc.lower_ & 0x20UL) {
          count += 3;
        }
      } else if (my_disc.lower_ & 0x1000UL) {
        count += 2;
      }
    } else if (my_disc.lower_ & 0x80000UL) {
      count += 1;
    }
  }
  return count;
}

static int g_42(const bit_matrix& my_disc, const bit_matrix& op_disc) {
  int count = 0;
  if (op_disc.upper_ & 0x8UL) {
    if (op_disc.upper_ & 0x10UL) {
      if (op_disc.upper_ & 0x20UL) {
        if (op_disc.upper_ & 0x40UL) {
          if (my_disc.upper_ & 0x80UL) {
            count += 4;
          }
        } else if (my_disc.upper_ & 0x40UL) {
          count += 3;
        }
      } else if (my_disc.upper_ & 0x20UL) {
        count += 2;
      }
    } else if (my_disc.upper_ & 0x10UL) {
      count += 1;
    }
  }
  if (op_disc.upper_ & 0x2UL) {
    if (my_disc.upper_ & 0x1UL) {
      count += 1;
    }
  }
  if (op_disc.upper_ & 0x400UL) {
    if (op_disc.upper_ & 0x40000UL) {
      if (my_disc.upper_ & 0x4000000UL) {
        count += 2;
      }
    } else if (my_disc.upper_ & 0x40000UL) {
      count += 1;
    }
  }
  if (op_disc.lower_ & 0x4000000UL) {
    if (op_disc.lower_ & 0x40000UL) {
      if (op_disc.lower_ & 0x400UL) {
        if (my_disc.lower_ & 0x4UL) {
          count += 3;
        }
      } else if (my_disc.lower_ & 0x400UL) {
        count += 2;
      }
    } else if (my_disc.lower_ & 0x40000UL) {
      count += 1;
    }
  }
  if (op_disc.upper_ & 0x800UL) {
    if (op_disc.upper_ & 0x100000UL) {
      if (my_disc.upper_ & 0x20000000UL) {
        count += 2;
      }
    } else if (my_disc.upper_ & 0x100000UL) {
      count += 1;
    }
  }
  if (op_disc.lower_ & 0x8000000UL) {
    if (op_disc.lower_ & 0x100000UL) {
      if (op_disc.lower_ & 0x2000UL) {
        if (my_disc.lower_ & 0x40UL) {
          count += 3;
        }
      } else if (my_disc.lower_ & 0x2000UL) {
        count += 2;
      }
    } else if (my_disc.lower_ & 0x100000UL) {
      count += 1;
    }
  }
  if (op_disc.upper_ & 0x200UL) {
    if (my_disc.upper_ & 0x10000UL) {
      count += 1;
    }
  }
  if (op_disc.lower_ & 0x2000000UL) {
    if (my_disc.lower_ & 0x10000UL) {
      count += 1;
    }
  }
  return count;
}

static int g_43(const bit_matrix& my_disc, const bit_matrix& op_disc) {
  int count = 0;
  if (op_disc.upper_ & 0x10UL) {
    if (op_disc.upper_ & 0x20UL) {
      if (op_disc.upper_ & 0x40UL) {
        if (my_disc.upper_ & 0x80UL) {
          count += 3;
        }
      } else if (my_disc.upper_ & 0x40UL) {
        count += 2;
      }
    } else if (my_disc.upper_ & 0x20UL) {
      count += 1;
    }
  }
  if (op_disc.upper_ & 0x4UL) {
    if (op_disc.upper_ & 0x2UL) {
      if (my_disc.upper_ & 0x1UL) {
        count += 2;
      }
    } else if (my_disc.upper_ & 0x2UL) {
      count += 1;
    }
  }
  if (op_disc.upper_ & 0x800UL) {
    if (op_disc.upper_ & 0x80000UL) {
      if (my_disc.upper_ & 0x8000000UL) {
        count += 2;
      }
    } else if (my_disc.upper_ & 0x80000UL) {
      count += 1;
    }
  }
  if (op_disc.lower_ & 0x8000000UL) {
    if (op_disc.lower_ & 0x80000UL) {
      if (op_disc.lower_ & 0x800UL) {
        if (my_disc.lower_ & 0x8UL) {
          count += 3;
        }
      } else if (my_disc.lower_ & 0x800UL) {
        count += 2;
      }
    } else if (my_disc.lower_ & 0x80000UL) {
      count += 1;
    }
  }
  if (op_disc.upper_ & 0x1000UL) {
    if (op_disc.upper_ & 0x200000UL) {
      if (my_disc.upper_ & 0x40000000UL) {
        count += 2;
      }
    } else if (my_disc.upper_ & 0x200000UL) {
      count += 1;
    }
  }
  if (op_disc.lower_ & 0x10000000UL) {
    if (op_disc.lower_ & 0x200000UL) {
      if (op_disc.lower_ & 0x4000UL) {
        if (my_disc.lower_ & 0x80UL) {
          count += 3;
        }
      } else if (my_disc.lower_ & 0x4000UL) {
        count += 2;
      }
    } else if (my_disc.lower_ & 0x200000UL) {
      count += 1;
    }
  }
  if (op_disc.upper_ & 0x400UL) {
    if (op_disc.upper_ & 0x20000UL) {
      if (my_disc.upper_ & 0x1000000UL) {
        count += 2;
      }
    } else if (my_disc.upper_ & 0x20000UL) {
      count += 1;
    }
  }
  if (op_disc.lower_ & 0x4000000UL) {
    if (op_disc.lower_ & 0x20000UL) {
      if (my_disc.lower_ & 0x100UL) {
        count += 2;
      }
    } else if (my_disc.lower_ & 0x20000UL) {
      count += 1;
    }
  }
  return count;
}

static int g_44(const bit_matrix& my_disc, const bit_matrix& op_disc) {
  int count = 0;
  if (op_disc.upper_ & 0x20UL) {
    if (op_disc.upper_ & 0x40UL) {
      if (my_disc.upper_ & 0x80UL) {
        count += 2;
      }
    } else if (my_disc.upper_ & 0x40UL) {
      count += 1;
    }
  }
  if (op_disc.upper_ & 0x8UL) {
    if (op_disc.upper_ & 0x4UL) {
      if (op_disc.upper_ & 0x2UL) {
        if (my_disc.upper_ & 0x1UL) {
          count += 3;
        }
      } else if (my_disc.upper_ & 0x2UL) {
        count += 2;
      }
    } else if (my_disc.upper_ & 0x4UL) {
      count += 1;
    }
  }
  if (op_disc.upper_ & 0x1000UL) {
    if (op_disc.upper_ & 0x100000UL) {
      if (my_disc.upper_ & 0x10000000UL) {
        count += 2;
      }
    } else if (my_disc.upper_ & 0x100000UL) {
      count += 1;
    }
  }
  if (op_disc.lower_ & 0x10000000UL) {
    if (op_disc.lower_ & 0x100000UL) {
      if (op_disc.lower_ & 0x1000UL) {
        if (my_disc.lower_ & 0x10UL) {
          count += 3;
        }
      } else if (my_disc.lower_ & 0x1000UL) {
        count += 2;
      }
    } else if (my_disc.lower_ & 0x100000UL) {
      count += 1;
    }
  }
  if (op_disc.upper_ & 0x2000UL) {
    if (op_disc.upper_ & 0x400000UL) {
      if (my_disc.upper_ & 0x80000000UL) {
        count += 2;
      }
    } else if (my_disc.upper_ & 0x400000UL) {
      count += 1;
    }
  }
  if (op_disc.lower_ & 0x20000000UL) {
    if (op_disc.lower_ & 0x400000UL) {
      if (my_disc.lower_ & 0x8000UL) {
        count += 2;
      }
    } else if (my_disc.lower_ & 0x400000UL) {
      count += 1;
    }
  }
  if (op_disc.upper_ & 0x800UL) {
    if (op_disc.upper_ & 0x40000UL) {
      if (my_disc.upper_ & 0x2000000UL) {
        count += 2;
      }
    } else if (my_disc.upper_ & 0x40000UL) {
      count += 1;
    }
  }
  if (op_disc.lower_ & 0x8000000UL) {
    if (op_disc.lower_ & 0x40000UL) {
      if (op_disc.lower_ & 0x200UL) {
        if (my_disc.lower_ & 0x1UL) {
          count += 3;
        }
      } else if (my_disc.lower_ & 0x200UL) {
        count += 2;
      }
    } else if (my_disc.lower_ & 0x40000UL) {
      count += 1;
    }
  }
  return count;
}

static int g_45(const bit_matrix& my_disc, const bit_matrix& op_disc) {
  int count = 0;
  if (op_disc.upper_ & 0x40UL) {
    if (my_disc.upper_ & 0x80UL) {
      count += 1;
    }
  }
  if (op_disc.upper_ & 0x10UL) {
    if (op_disc.upper_ & 0x8UL) {
      if (op_disc.upper_ & 0x4UL) {
        if (op_disc.upper_ & 0x2UL) {
          if (my_disc.upper_ & 0x1UL) {
            count += 4;
          }
        } else if (my_disc.upper_ & 0x2UL) {
          count += 3;
        }
      } else if (my_disc.upper_ & 0x4UL) {
        count += 2;
      }
    } else if (my_disc.upper_ & 0x8UL) {
      count += 1;
    }
  }
  if (op_disc.upper_ & 0x2000UL) {
    if (op_disc.upper_ & 0x200000UL) {
      if (my_disc.upper_ & 0x20000000UL) {
        count += 2;
      }
    } else if (my_disc.upper_ & 0x200000UL) {
      count += 1;
    }
  }
  if (op_disc.lower_ & 0x20000000UL) {
    if (op_disc.lower_ & 0x200000UL) {
      if (op_disc.lower_ & 0x2000UL) {
        if (my_disc.lower_ & 0x20UL) {
          count += 3;
        }
      } else if (my_disc.lower_ & 0x2000UL) {
        count += 2;
      }
    } else if (my_disc.lower_ & 0x200000UL) {
      count += 1;
    }
  }
  if (op_disc.upper_ & 0x4000UL) {
    if (my_disc.upper_ & 0x800000UL) {
      count += 1;
    }
  }
  if (op_disc.lower_ & 0x40000000UL) {
    if (my_disc.lower_ & 0x800000UL) {
      count += 1;
    }
  }
  if (op_disc.upper_ & 0x1000UL) {
    if (op_disc.upper_ & 0x80000UL) {
      if (my_disc.upper_ & 0x4000000UL) {
        count += 2;
      }
    } else if (my_disc.upper_ & 0x80000UL) {
      count += 1;
    }
  }
  if (op_disc.lower_ & 0x10000000UL) {
    if (op_disc.lower_ & 0x80000UL) {
      if (op_disc.lower_ & 0x400UL) {
        if (my_disc.lower_ & 0x2UL) {
          count += 3;
        }
      } else if (my_disc.lower_ & 0x400UL) {
        count += 2;
      }
    } else if (my_disc.lower_ & 0x80000UL) {
      count += 1;
    }
  }
  return count;
}

static int g_46(const bit_matrix& my_disc, const bit_matrix& op_disc) {
  int count = 0;
  if (op_disc.upper_ & 0x20UL) {
    if (op_disc.upper_ & 0x10UL) {
      if (op_disc.upper_ & 0x8UL) {
        if (op_disc.upper_ & 0x4UL) {
          if (op_disc.upper_ & 0x2UL) {
            if (my_disc.upper_ & 0x1UL) {
              count += 5;
            }
          } else if (my_disc.upper_ & 0x2UL) {
            count += 4;
          }
        } else if (my_disc.upper_ & 0x4UL) {
          count += 3;
        }
      } else if (my_disc.upper_ & 0x8UL) {
        count += 2;
      }
    } else if (my_disc.upper_ & 0x10UL) {
      count += 1;
    }
  }
  if (op_disc.upper_ & 0x4000UL) {
    if (op_disc.upper_ & 0x400000UL) {
      if (my_disc.upper_ & 0x40000000UL) {
        count += 2;
      }
    } else if (my_disc.upper_ & 0x400000UL) {
      count += 1;
    }
  }
  if (op_disc.lower_ & 0x40000000UL) {
    if (op_disc.lower_ & 0x400000UL) {
      if (op_disc.lower_ & 0x4000UL) {
        if (my_disc.lower_ & 0x40UL) {
          count += 3;
        }
      } else if (my_disc.lower_ & 0x4000UL) {
        count += 2;
      }
    } else if (my_disc.lower_ & 0x400000UL) {
      count += 1;
    }
  }
  if (op_disc.upper_ & 0x2000UL) {
    if (op_disc.upper_ & 0x100000UL) {
      if (my_disc.upper_ & 0x8000000UL) {
        count += 2;
      }
    } else if (my_disc.upper_ & 0x100000UL) {
      count += 1;
    }
  }
  if (op_disc.lower_ & 0x20000000UL) {
    if (op_disc.lower_ & 0x100000UL) {
      if (op_disc.lower_ & 0x800UL) {
        if (my_disc.lower_ & 0x4UL) {
          count += 3;
        }
      } else if (my_disc.lower_ & 0x800UL) {
        count += 2;
      }
    } else if (my_disc.lower_ & 0x100000UL) {
      count += 1;
    }
  }
  return count;
}

static int g_47(const bit_matrix& my_disc, const bit_matrix& op_disc) {
  int count = 0;
  if (op_disc.upper_ & 0x40UL) {
    if (op_disc.upper_ & 0x20UL) {
      if (op_disc.upper_ & 0x10UL) {
        if (op_disc.upper_ & 0x8UL) {
          if (op_disc.upper_ & 0x4UL) {
            if (op_disc.upper_ & 0x2UL) {
              if (my_disc.upper_ & 0x1UL) {
                count += 6;
              }
            } else if (my_disc.upper_ & 0x2UL) {
              count += 5;
            }
          } else if (my_disc.upper_ & 0x4UL) {
            count += 4;
          }
        } else if (my_disc.upper_ & 0x8UL) {
          count += 3;
        }
      } else if (my_disc.upper_ & 0x10UL) {
        count += 2;
      }
    } else if (my_disc.upper_ & 0x20UL) {
      count += 1;
    }
  }
  if (op_disc.upper_ & 0x8000UL) {
    if (op_disc.upper_ & 0x800000UL) {
      if (my_disc.upper_ & 0x80000000UL) {
        count += 2;
      }
    } else if (my_disc.upper_ & 0x800000UL) {
      count += 1;
    }
  }
  if (op_disc.lower_ & 0x80000000UL) {
    if (op_disc.lower_ & 0x800000UL) {
      if (op_disc.lower_ & 0x8000UL) {
        if (my_disc.lower_ & 0x80UL) {
          count += 3;
        }
      } else if (my_disc.lower_ & 0x8000UL) {
        count += 2;
      }
    } else if (my_disc.lower_ & 0x800000UL) {
      count += 1;
    }
  }
  if (op_disc.upper_ & 0x4000UL) {
    if (op_disc.upper_ & 0x200000UL) {
      if (my_disc.upper_ & 0x10000000UL) {
        count += 2;
      }
    } else if (my_disc.upper_ & 0x200000UL) {
      count += 1;
    }
  }
  if (op_disc.lower_ & 0x40000000UL) {
    if (op_disc.lower_ & 0x200000UL) {
      if (op_disc.lower_ & 0x1000UL) {
        if (my_disc.lower_ & 0x8UL) {
          count += 3;
        }
      } else if (my_disc.lower_ & 0x1000UL) {
        count += 2;
      }
    } else if (my_disc.lower_ & 0x200000UL) {
      count += 1;
    }
  }
  return count;
}

static int g_50(const bit_matrix& my_disc, const bit_matrix& op_disc) {
  int count = 0;
  if (op_disc.upper_ & 0x200UL) {
    if (op_disc.upper_ & 0x400UL) {
      if (op_disc.upper_ & 0x800UL) {
        if (op_disc.upper_ & 0x1000UL) {
          if (op_disc.upper_ & 0x2000UL) {
            if (op_disc.upper_ & 0x4000UL) {
              if (my_disc.upper_ & 0x8000UL) {
                count += 6;
              }
            } else if (my_disc.upper_ & 0x4000UL) {
              count += 5;
            }
          } else if (my_disc.upper_ & 0x2000UL) {
            count += 4;
          }
        } else if (my_disc.upper_ & 0x1000UL) {
          count += 3;
        }
      } else if (my_disc.upper_ & 0x800UL) {
        count += 2;
      }
    } else if (my_disc.upper_ & 0x400UL) {
      count += 1;
    }
  }
  if (op_disc.upper_ & 0x10000UL) {
    if (my_disc.upper_ & 0x1000000UL) {
      count += 1;
    }
  }
  if (op_disc.upper_ & 0x1UL) {
    if (op_disc.lower_ & 0x1000000UL) {
      if (op_disc.lower_ & 0x10000UL) {
        if (op_disc.lower_ & 0x100UL) {
          if (my_disc.lower_ & 0x1UL) {
            count += 4;
          }
        } else if (my_disc.lower_ & 0x100UL) {
          count += 3;
        }
      } else if (my_disc.lower_ & 0x10000UL) {
        count += 2;
      }
    } else if (my_disc.lower_ & 0x1000000UL) {
      count += 1;
    }
  }
  if (op_disc.upper_ & 0x20000UL) {
    if (my_disc.upper_ & 0x4000000UL) {
      count += 1;
    }
  }
  if (op_disc.upper_ & 0x2UL) {
    if (op_disc.lower_ & 0x4000000UL) {
      if (op_disc.lower_ & 0x80000UL) {
        if (op_disc.lower_ & 0x1000UL) {
          if (my_disc.lower_ & 0x20UL) {
            count += 4;
          }
        } else if (my_disc.lower_ & 0x1000UL) {
          count += 3;
        }
      } else if (my_disc.lower_ & 0x80000UL) {
        count += 2;
      }
    } else if (my_disc.lower_ & 0x4000000UL) {
      count += 1;
    }
  }
  return count;
}

static int g_51(const bit_matrix& my_disc, const bit_matrix& op_disc) {
  int count = 0;
  if (op_disc.upper_ & 0x400UL) {
    if (op_disc.upper_ & 0x800UL) {
      if (op_disc.upper_ & 0x1000UL) {
        if (op_disc.upper_ & 0x2000UL) {
          if (op_disc.upper_ & 0x4000UL) {
            if (my_disc.upper_ & 0x8000UL) {
              count += 5;
            }
          } else if (my_disc.upper_ & 0x4000UL) {
            count += 4;
          }
        } else if (my_disc.upper_ & 0x2000UL) {
          count += 3;
        }
      } else if (my_disc.upper_ & 0x1000UL) {
        count += 2;
      }
    } else if (my_disc.upper_ & 0x800UL) {
      count += 1;
    }
  }
  if (op_disc.upper_ & 0x20000UL) {
    if (my_disc.upper_ & 0x2000000UL) {
      count += 1;
    }
  }
  if (op_disc.upper_ & 0x2UL) {
    if (op_disc.lower_ & 0x2000000UL) {
      if (op_disc.lower_ & 0x20000UL) {
        if (op_disc.lower_ & 0x200UL) {
          if (my_disc.lower_ & 0x2UL) {
            count += 4;
          }
        } else if (my_disc.lower_ & 0x200UL) {
          count += 3;
        }
      } else if (my_disc.lower_ & 0x20000UL) {
        count += 2;
      }
    } else if (my_disc.lower_ & 0x2000000UL) {
      count += 1;
    }
  }
  if (op_disc.upper_ & 0x40000UL) {
    if (my_disc.upper_ & 0x8000000UL) {
      count += 1;
    }
  }
  if (op_disc.upper_ & 0x4UL) {
    if (op_disc.lower_ & 0x8000000UL) {
      if (op_disc.lower_ & 0x100000UL) {
        if (op_disc.lower_ & 0x2000UL) {
          if (my_disc.lower_ & 0x40UL) {
            count += 4;
          }
        } else if (my_disc.lower_ & 0x2000UL) {
          count += 3;
        }
      } else if (my_disc.lower_ & 0x100000UL) {
        count += 2;
      }
    } else if (my_disc.lower_ & 0x8000000UL) {
      count += 1;
    }
  }
  return count;
}

static int g_52(const bit_matrix& my_disc, const bit_matrix& op_disc) {
  int count = 0;
  if (op_disc.upper_ & 0x800UL) {
    if (op_disc.upper_ & 0x1000UL) {
      if (op_disc.upper_ & 0x2000UL) {
        if (op_disc.upper_ & 0x4000UL) {
          if (my_disc.upper_ & 0x8000UL) {
            count += 4;
          }
        } else if (my_disc.upper_ & 0x4000UL) {
          count += 3;
        }
      } else if (my_disc.upper_ & 0x2000UL) {
        count += 2;
      }
    } else if (my_disc.upper_ & 0x1000UL) {
      count += 1;
    }
  }
  if (op_disc.upper_ & 0x200UL) {
    if (my_disc.upper_ & 0x100UL) {
      count += 1;
    }
  }
  if (op_disc.upper_ & 0x40000UL) {
    if (my_disc.upper_ & 0x4000000UL) {
      count += 1;
    }
  }
  if (op_disc.upper_ & 0x4UL) {
    if (op_disc.lower_ & 0x4000000UL) {
      if (op_disc.lower_ & 0x40000UL) {
        if (op_disc.lower_ & 0x400UL) {
          if (my_disc.lower_ & 0x4UL) {
            count += 4;
          }
        } else if (my_disc.lower_ & 0x400UL) {
          count += 3;
        }
      } else if (my_disc.lower_ & 0x40000UL) {
        count += 2;
      }
    } else if (my_disc.lower_ & 0x4000000UL) {
      count += 1;
    }
  }
  if (op_disc.upper_ & 0x80000UL) {
    if (my_disc.upper_ & 0x10000000UL) {
      count += 1;
    }
  }
  if (op_disc.upper_ & 0x8UL) {
    if (op_disc.lower_ & 0x10000000UL) {
      if (op_disc.lower_ & 0x200000UL) {
        if (op_disc.lower_ & 0x4000UL) {
          if (my_disc.lower_ & 0x80UL) {
            count += 4;
          }
        } else if (my_disc.lower_ & 0x4000UL) {
          count += 3;
        }
      } else if (my_disc.lower_ & 0x200000UL) {
        count += 2;
      }
    } else if (my_disc.lower_ & 0x10000000UL) {
      count += 1;
    }
  }
  if (op_disc.upper_ & 0x20000UL) {
    if (my_disc.upper_ & 0x1000000UL) {
      count += 1;
    }
  }
  if (op_disc.upper_ & 0x2UL) {
    if (my_disc.lower_ & 0x1000000UL) {
      count += 1;
    }
  }
  return count;
}

static int g_53(const bit_matrix& my_disc, const bit_matrix& op_disc) {
  int count = 0;
  if (op_disc.upper_ & 0x1000UL) {
    if (op_disc.upper_ & 0x2000UL) {
      if (op_disc.upper_ & 0x4000UL) {
        if (my_disc.upper_ & 0x8000UL) {
          count += 3;
        }
      } else if (my_disc.upper_ & 0x4000UL) {
        count += 2;
      }
    } else if (my_disc.upper_ & 0x2000UL) {
      count += 1;
    }
  }
  if (op_disc.upper_ & 0x400UL) {
    if (op_disc.upper_ & 0x200UL) {
      if (my_disc.upper_ & 0x100UL) {
        count += 2;
      }
    } else if (my_disc.upper_ & 0x200UL) {
      count += 1;
    }
  }
  if (op_disc.upper_ & 0x80000UL) {
    if (my_disc.upper_ & 0x8000000UL) {
      count += 1;
    }
  }
  if (op_disc.upper_ & 0x8UL) {
    if (op_disc.lower_ & 0x8000000UL) {
      if (op_disc.lower_ & 0x80000UL) {
        if (op_disc.lower_ & 0x800UL) {
          if (my_disc.lower_ & 0x8UL) {
            count += 4;
          }
        } else if (my_disc.lower_ & 0x800UL) {
          count += 3;
        }
      } else if (my_disc.lower_ & 0x80000UL) {
        count += 2;
      }
    } else if (my_disc.lower_ & 0x8000000UL) {
      count += 1;
    }
  }
  if (op_disc.upper_ & 0x100000UL) {
    if (my_disc.upper_ & 0x20000000UL) {
      count += 1;
    }
  }
  if (op_disc.upper_ & 0x10UL) {
    if (op_disc.lower_ & 0x20000000UL) {
      if (op_disc.lower_ & 0x400000UL) {
        if (my_disc.lower_ & 0x8000UL) {
          count += 3;
        }
      } else if (my_disc.lower_ & 0x400000UL) {
        count += 2;
      }
    } else if (my_disc.lower_ & 0x20000000UL) {
      count += 1;
    }
  }
  if (op_disc.upper_ & 0x40000UL) {
    if (my_disc.upper_ & 0x2000000UL) {
      count += 1;
    }
  }
  if (op_disc.upper_ & 0x4UL) {
    if (op_disc.lower_ & 0x2000000UL) {
      if (my_disc.lower_ & 0x10000UL) {
        count += 2;
      }
    } else if (my_disc.lower_ & 0x2000000UL) {
      count += 1;
    }
  }
  return count;
}

static int g_54(const bit_matrix& my_disc, const bit_matrix& op_disc) {
  int count = 0;
  if (op_disc.upper_ & 0x2000UL) {
    if (op_disc.upper_ & 0x4000UL) {
      if (my_disc.upper_ & 0x8000UL) {
        count += 2;
      }
    } else if (my_disc.upper_ & 0x4000UL) {
      count += 1;
    }
  }
  if (op_disc.upper_ & 0x800UL) {
    if (op_disc.upper_ & 0x400UL) {
      if (op_disc.upper_ & 0x200UL) {
        if (my_disc.upper_ & 0x100UL) {
          count += 3;
        }
      } else if (my_disc.upper_ & 0x200UL) {
        count += 2;
      }
    } else if (my_disc.upper_ & 0x400UL) {
      count += 1;
    }
  }
  if (op_disc.upper_ & 0x100000UL) {
    if (my_disc.upper_ & 0x10000000UL) {
      count += 1;
    }
  }
  if (op_disc.upper_ & 0x10UL) {
    if (op_disc.lower_ & 0x10000000UL) {
      if (op_disc.lower_ & 0x100000UL) {
        if (op_disc.lower_ & 0x1000UL) {
          if (my_disc.lower_ & 0x10UL) {
            count += 4;
          }
        } else if (my_disc.lower_ & 0x1000UL) {
          count += 3;
        }
      } else if (my_disc.lower_ & 0x100000UL) {
        count += 2;
      }
    } else if (my_disc.lower_ & 0x10000000UL) {
      count += 1;
    }
  }
  if (op_disc.upper_ & 0x200000UL) {
    if (my_disc.upper_ & 0x40000000UL) {
      count += 1;
    }
  }
  if (op_disc.upper_ & 0x20UL) {
    if (op_disc.lower_ & 0x40000000UL) {
      if (my_disc.lower_ & 0x800000UL) {
        count += 2;
      }
    } else if (my_disc.lower_ & 0x40000000UL) {
      count += 1;
    }
  }
  if (op_disc.upper_ & 0x80000UL) {
    if (my_disc.upper_ & 0x4000000UL) {
      count += 1;
    }
  }
  if (op_disc.upper_ & 0x8UL) {
    if (op_disc.lower_ & 0x4000000UL) {
      if (op_disc.lower_ & 0x20000UL) {
        if (my_disc.lower_ & 0x100UL) {
          count += 3;
        }
      } else if (my_disc.lower_ & 0x20000UL) {
        count += 2;
      }
    } else if (my_disc.lower_ & 0x4000000UL) {
      count += 1;
    }
  }
  return count;
}

static int g_55(const bit_matrix& my_disc, const bit_matrix& op_disc) {
  int count = 0;
  if (op_disc.upper_ & 0x4000UL) {
    if (my_disc.upper_ & 0x8000UL) {
      count += 1;
    }
  }
  if (op_disc.upper_ & 0x1000UL) {
    if (op_disc.upper_ & 0x800UL) {
      if (op_disc.upper_ & 0x400UL) {
        if (op_disc.upper_ & 0x200UL) {
          if (my_disc.upper_ & 0x100UL) {
            count += 4;
          }
        } else if (my_disc.upper_ & 0x200UL) {
          count += 3;
        }
      } else if (my_disc.upper_ & 0x400UL) {
        count += 2;
      }
    } else if (my_disc.upper_ & 0x800UL) {
      count += 1;
    }
  }
  if (op_disc.upper_ & 0x200000UL) {
    if (my_disc.upper_ & 0x20000000UL) {
      count += 1;
    }
  }
  if (op_disc.upper_ & 0x20UL) {
    if (op_disc.lower_ & 0x20000000UL) {
      if (op_disc.lower_ & 0x200000UL) {
        if (op_disc.lower_ & 0x2000UL) {
          if (my_disc.lower_ & 0x20UL) {
            count += 4;
          }
        } else if (my_disc.lower_ & 0x2000UL) {
          count += 3;
        }
      } else if (my_disc.lower_ & 0x200000UL) {
        count += 2;
      }
    } else if (my_disc.lower_ & 0x20000000UL) {
      count += 1;
    }
  }
  if (op_disc.upper_ & 0x400000UL) {
    if (my_disc.upper_ & 0x80000000UL) {
      count += 1;
    }
  }
  if (op_disc.upper_ & 0x40UL) {
    if (my_disc.lower_ & 0x80000000UL) {
      count += 1;
    }
  }
  if (op_disc.upper_ & 0x100000UL) {
    if (my_disc.upper_ & 0x8000000UL) {
      count += 1;
    }
  }
  if (op_disc.upper_ & 0x10UL) {
    if (op_disc.lower_ & 0x8000000UL) {
      if (op_disc.lower_ & 0x40000UL) {
        if (op_disc.lower_ & 0x200UL) {
          if (my_disc.lower_ & 0x1UL) {
            count += 4;
          }
        } else if (my_disc.lower_ & 0x200UL) {
          count += 3;
        }
      } else if (my_disc.lower_ & 0x40000UL) {
        count += 2;
      }
    } else if (my_disc.lower_ & 0x8000000UL) {
      count += 1;
    }
  }
  return count;
}

static int g_56(const bit_matrix& my_disc, const bit_matrix& op_disc) {
  int count = 0;
  if (op_disc.upper_ & 0x2000UL) {
    if (op_disc.upper_ & 0x1000UL) {
      if (op_disc.upper_ & 0x800UL) {
        if (op_disc.upper_ & 0x400UL) {
          if (op_disc.upper_ & 0x200UL) {
            if (my_disc.upper_ & 0x100UL) {
              count += 5;
            }
          } else if (my_disc.upper_ & 0x200UL) {
            count += 4;
          }
        } else if (my_disc.upper_ & 0x400UL) {
          count += 3;
        }
      } else if (my_disc.upper_ & 0x800UL) {
        count += 2;
      }
    } else if (my_disc.upper_ & 0x1000UL) {
      count += 1;
    }
  }
  if (op_disc.upper_ & 0x400000UL) {
    if (my_disc.upper_ & 0x40000000UL) {
      count += 1;
    }
  }
  if (op_disc.upper_ & 0x40UL) {
    if (op_disc.lower_ & 0x40000000UL) {
      if (op_disc.lower_ & 0x400000UL) {
        if (op_disc.lower_ & 0x4000UL) {
          if (my_disc.lower_ & 0x40UL) {
            count += 4;
          }
        } else if (my_disc.lower_ & 0x4000UL) {
          count += 3;
        }
      } else if (my_disc.lower_ & 0x400000UL) {
        count += 2;
      }
    } else if (my_disc.lower_ & 0x40000000UL) {
      count += 1;
    }
  }
  if (op_disc.upper_ & 0x200000UL) {
    if (my_disc.upper_ & 0x10000000UL) {
      count += 1;
    }
  }
  if (op_disc.upper_ & 0x20UL) {
    if (op_disc.lower_ & 0x10000000UL) {
      if (op_disc.lower_ & 0x80000UL) {
        if (op_disc.lower_ & 0x400UL) {
          if (my_disc.lower_ & 0x2UL) {
            count += 4;
          }
        } else if (my_disc.lower_ & 0x400UL) {
          count += 3;
        }
      } else if (my_disc.lower_ & 0x80000UL) {
        count += 2;
      }
    } else if (my_disc.lower_ & 0x10000000UL) {
      count += 1;
    }
  }
  return count;
}

static int g_57(const bit_matrix& my_disc, const bit_matrix& op_disc) {
  int count = 0;
  if (op_disc.upper_ & 0x4000UL) {
    if (op_disc.upper_ & 0x2000UL) {
      if (op_disc.upper_ & 0x1000UL) {
        if (op_disc.upper_ & 0x800UL) {
          if (op_disc.upper_ & 0x400UL) {
            if (op_disc.upper_ & 0x200UL) {
              if (my_disc.upper_ & 0x100UL) {
                count += 6;
              }
            } else if (my_disc.upper_ & 0x200UL) {
              count += 5;
            }
          } else if (my_disc.upper_ & 0x400UL) {
            count += 4;
          }
        } else if (my_disc.upper_ & 0x800UL) {
          count += 3;
        }
      } else if (my_disc.upper_ & 0x1000UL) {
        count += 2;
      }
    } else if (my_disc.upper_ & 0x2000UL) {
      count += 1;
    }
  }
  if (op_disc.upper_ & 0x800000UL) {
    if (my_disc.upper_ & 0x80000000UL) {
      count += 1;
    }
  }
  if (op_disc.upper_ & 0x80UL) {
    if (op_disc.lower_ & 0x80000000UL) {
      if (op_disc.lower_ & 0x800000UL) {
        if (op_disc.lower_ & 0x8000UL) {
          if (my_disc.lower_ & 0x80UL) {
            count += 4;
          }
        } else if (my_disc.lower_ & 0x8000UL) {
          count += 3;
        }
      } else if (my_disc.lower_ & 0x800000UL) {
        count += 2;
      }
    } else if (my_disc.lower_ & 0x80000000UL) {
      count += 1;
    }
  }
  if (op_disc.upper_ & 0x400000UL) {
    if (my_disc.upper_ & 0x20000000UL) {
      count += 1;
    }
  }
  if (op_disc.upper_ & 0x40UL) {
    if (op_disc.lower_ & 0x20000000UL) {
      if (op_disc.lower_ & 0x100000UL) {
        if (op_disc.lower_ & 0x800UL) {
          if (my_disc.lower_ & 0x4UL) {
            count += 4;
          }
        } else if (my_disc.lower_ & 0x800UL) {
          count += 3;
        }
      } else if (my_disc.lower_ & 0x100000UL) {
        count += 2;
      }
    } else if (my_disc.lower_ & 0x20000000UL) {
      count += 1;
    }
  }
  return count;
}

static int g_60(const bit_matrix& my_disc, const bit_matrix& op_disc) {
  int count = 0;
  if (op_disc.upper_ & 0x20000UL) {
    if (op_disc.upper_ & 0x40000UL) {
      if (op_disc.upper_ & 0x80000UL) {
        if (op_disc.upper_ & 0x100000UL) {
          if (op_disc.upper_ & 0x200000UL) {
            if (op_disc.upper_ & 0x400000UL) {
              if (my_disc.upper_ & 0x800000UL) {
                count += 6;
              }
            } else if (my_disc.upper_ & 0x400000UL) {
              count += 5;
            }
          } else if (my_disc.upper_ & 0x200000UL) {
            count += 4;
          }
        } else if (my_disc.upper_ & 0x100000UL) {
          count += 3;
        }
      } else if (my_disc.upper_ & 0x80000UL) {
        count += 2;
      }
    } else if (my_disc.upper_ & 0x40000UL) {
      count += 1;
    }
  }
  if (op_disc.upper_ & 0x100UL) {
    if (op_disc.upper_ & 0x1UL) {
      if (op_disc.lower_ & 0x1000000UL) {
        if (op_disc.lower_ & 0x10000UL) {
          if (op_disc.lower_ & 0x100UL) {
            if (my_disc.lower_ & 0x1UL) {
              count += 5;
            }
          } else if (my_disc.lower_ & 0x100UL) {
            count += 4;
          }
        } else if (my_disc.lower_ & 0x10000UL) {
          count += 3;
        }
      } else if (my_disc.lower_ & 0x1000000UL) {
        count += 2;
      }
    } else if (my_disc.upper_ & 0x1UL) {
      count += 1;
    }
  }
  if (op_disc.upper_ & 0x200UL) {
    if (op_disc.upper_ & 0x4UL) {
      if (op_disc.lower_ & 0x8000000UL) {
        if (op_disc.lower_ & 0x100000UL) {
          if (op_disc.lower_ & 0x2000UL) {
            if (my_disc.lower_ & 0x40UL) {
              count += 5;
            }
          } else if (my_disc.lower_ & 0x2000UL) {
            count += 4;
          }
        } else if (my_disc.lower_ & 0x100000UL) {
          count += 3;
        }
      } else if (my_disc.lower_ & 0x8000000UL) {
        count += 2;
      }
    } else if (my_disc.upper_ & 0x4UL) {
      count += 1;
    }
  }
  return count;
}

static int g_61(const bit_matrix& my_disc, const bit_matrix& op_disc) {
  int count = 0;
  if (op_disc.upper_ & 0x40000UL) {
    if (op_disc.upper_ & 0x80000UL) {
      if (op_disc.upper_ & 0x100000UL) {
        if (op_disc.upper_ & 0x200000UL) {
          if (op_disc.upper_ & 0x400000UL) {
            if (my_disc.upper_ & 0x800000UL) {
              count += 5;
            }
          } else if (my_disc.upper_ & 0x400000UL) {
            count += 4;
          }
        } else if (my_disc.upper_ & 0x200000UL) {
          count += 3;
        }
      } else if (my_disc.upper_ & 0x100000UL) {
        count += 2;
      }
    } else if (my_disc.upper_ & 0x80000UL) {
      count += 1;
    }
  }
  if (op_disc.upper_ & 0x200UL) {
    if (op_disc.upper_ & 0x2UL) {
      if (op_disc.lower_ & 0x2000000UL) {
        if (op_disc.lower_ & 0x20000UL) {
          if (op_disc.lower_ & 0x200UL) {
            if (my_disc.lower_ & 0x2UL) {
              count += 5;
            }
          } else if (my_disc.lower_ & 0x200UL) {
            count += 4;
          }
        } else if (my_disc.lower_ & 0x20000UL) {
          count += 3;
        }
      } else if (my_disc.lower_ & 0x2000000UL) {
        count += 2;
      }
    } else if (my_disc.upper_ & 0x2UL) {
      count += 1;
    }
  }
  if (op_disc.upper_ & 0x400UL) {
    if (op_disc.upper_ & 0x8UL) {
      if (op_disc.lower_ & 0x10000000UL) {
        if (op_disc.lower_ & 0x200000UL) {
          if (op_disc.lower_ & 0x4000UL) {
            if (my_disc.lower_ & 0x80UL) {
              count += 5;
            }
          } else if (my_disc.lower_ & 0x4000UL) {
            count += 4;
          }
        } else if (my_disc.lower_ & 0x200000UL) {
          count += 3;
        }
      } else if (my_disc.lower_ & 0x10000000UL) {
        count += 2;
      }
    } else if (my_disc.upper_ & 0x8UL) {
      count += 1;
    }
  }
  return count;
}

static int g_62(const bit_matrix& my_disc, const bit_matrix& op_disc) {
  int count = 0;
  if (op_disc.upper_ & 0x80000UL) {
    if (op_disc.upper_ & 0x100000UL) {
      if (op_disc.upper_ & 0x200000UL) {
        if (op_disc.upper_ & 0x400000UL) {
          if (my_disc.upper_ & 0x800000UL) {
            count += 4;
          }
        } else if (my_disc.upper_ & 0x400000UL) {
          count += 3;
        }
      } else if (my_disc.upper_ & 0x200000UL) {
        count += 2;
      }
    } else if (my_disc.upper_ & 0x100000UL) {
      count += 1;
    }
  }
  if (op_disc.upper_ & 0x20000UL) {
    if (my_disc.upper_ & 0x10000UL) {
      count += 1;
    }
  }
  if (op_disc.upper_ & 0x400UL) {
    if (op_disc.upper_ & 0x4UL) {
      if (op_disc.lower_ & 0x4000000UL) {
        if (op_disc.lower_ & 0x40000UL) {
          if (op_disc.lower_ & 0x400UL) {
            if (my_disc.lower_ & 0x4UL) {
              count += 5;
            }
          } else if (my_disc.lower_ & 0x400UL) {
            count += 4;
          }
        } else if (my_disc.lower_ & 0x40000UL) {
          count += 3;
        }
      } else if (my_disc.lower_ & 0x4000000UL) {
        count += 2;
      }
    } else if (my_disc.upper_ & 0x4UL) {
      count += 1;
    }
  }
  if (op_disc.upper_ & 0x800UL) {
    if (op_disc.upper_ & 0x10UL) {
      if (op_disc.lower_ & 0x20000000UL) {
        if (op_disc.lower_ & 0x400000UL) {
          if (my_disc.lower_ & 0x8000UL) {
            count += 4;
          }
        } else if (my_disc.lower_ & 0x400000UL) {
          count += 3;
        }
      } else if (my_disc.lower_ & 0x20000000UL) {
        count += 2;
      }
    } else if (my_disc.upper_ & 0x10UL) {
      count += 1;
    }
  }
  if (op_disc.upper_ & 0x200UL) {
    if (my_disc.upper_ & 0x1UL) {
      count += 1;
    }
  }
  return count;
}

static int g_63(const bit_matrix& my_disc, const bit_matrix& op_disc) {
  int count = 0;
  if (op_disc.upper_ & 0x100000UL) {
    if (op_disc.upper_ & 0x200000UL) {
      if (op_disc.upper_ & 0x400000UL) {
        if (my_disc.upper_ & 0x800000UL) {
          count += 3;
        }
      } else if (my_disc.upper_ & 0x400000UL) {
        count += 2;
      }
    } else if (my_disc.upper_ & 0x200000UL) {
      count += 1;
    }
  }
  if (op_disc.upper_ & 0x40000UL) {
    if (op_disc.upper_ & 0x20000UL) {
      if (my_disc.upper_ & 0x10000UL) {
        count += 2;
      }
    } else if (my_disc.upper_ & 0x20000UL) {
      count += 1;
    }
  }
  if (op_disc.upper_ & 0x800UL) {
    if (op_disc.upper_ & 0x8UL) {
      if (op_disc.lower_ & 0x8000000UL) {
        if (op_disc.lower_ & 0x80000UL) {
          if (op_disc.lower_ & 0x800UL) {
            if (my_disc.lower_ & 0x8UL) {
              count += 5;
            }
          } else if (my_disc.lower_ & 0x800UL) {
            count += 4;
          }
        } else if (my_disc.lower_ & 0x80000UL) {
          count += 3;
        }
      } else if (my_disc.lower_ & 0x8000000UL) {
        count += 2;
      }
    } else if (my_disc.upper_ & 0x8UL) {
      count += 1;
    }
  }
  if (op_disc.upper_ & 0x1000UL) {
    if (op_disc.upper_ & 0x20UL) {
      if (op_disc.lower_ & 0x40000000UL) {
        if (my_disc.lower_ & 0x800000UL) {
          count += 3;
        }
      } else if (my_disc.lower_ & 0x40000000UL) {
        count += 2;
      }
    } else if (my_disc.upper_ & 0x20UL) {
      count += 1;
    }
  }
  if (op_disc.upper_ & 0x400UL) {
    if (op_disc.upper_ & 0x2UL) {
      if (my_disc.lower_ & 0x1000000UL) {
        count += 2;
      }
    } else if (my_disc.upper_ & 0x2UL) {
      count += 1;
    }
  }
  return count;
}

static int g_64(const bit_matrix& my_disc, const bit_matrix& op_disc) {
  int count = 0;
  if (op_disc.upper_ & 0x200000UL) {
    if (op_disc.upper_ & 0x400000UL) {
      if (my_disc.upper_ & 0x800000UL) {
        count += 2;
      }
    } else if (my_disc.upper_ & 0x400000UL) {
      count += 1;
    }
  }
  if (op_disc.upper_ & 0x80000UL) {
    if (op_disc.upper_ & 0x40000UL) {
      if (op_disc.upper_ & 0x20000UL) {
        if (my_disc.upper_ & 0x10000UL) {
          count += 3;
        }
      } else if (my_disc.upper_ & 0x20000UL) {
        count += 2;
      }
    } else if (my_disc.upper_ & 0x40000UL) {
      count += 1;
    }
  }
  if (op_disc.upper_ & 0x1000UL) {
    if (op_disc.upper_ & 0x10UL) {
      if (op_disc.lower_ & 0x10000000UL) {
        if (op_disc.lower_ & 0x100000UL) {
          if (op_disc.lower_ & 0x1000UL) {
            if (my_disc.lower_ & 0x10UL) {
              count += 5;
            }
          } else if (my_disc.lower_ & 0x1000UL) {
            count += 4;
          }
        } else if (my_disc.lower_ & 0x100000UL) {
          count += 3;
        }
      } else if (my_disc.lower_ & 0x10000000UL) {
        count += 2;
      }
    } else if (my_disc.upper_ & 0x10UL) {
      count += 1;
    }
  }
  if (op_disc.upper_ & 0x2000UL) {
    if (op_disc.upper_ & 0x40UL) {
      if (my_disc.lower_ & 0x80000000UL) {
        count += 2;
      }
    } else if (my_disc.upper_ & 0x40UL) {
      count += 1;
    }
  }
  if (op_disc.upper_ & 0x800UL) {
    if (op_disc.upper_ & 0x4UL) {
      if (op_disc.lower_ & 0x2000000UL) {
        if (my_disc.lower_ & 0x10000UL) {
          count += 3;
        }
      } else if (my_disc.lower_ & 0x2000000UL) {
        count += 2;
      }
    } else if (my_disc.upper_ & 0x4UL) {
      count += 1;
    }
  }
  return count;
}

static int g_65(const bit_matrix& my_disc, const bit_matrix& op_disc) {
  int count = 0;
  if (op_disc.upper_ & 0x400000UL) {
    if (my_disc.upper_ & 0x800000UL) {
      count += 1;
    }
  }
  if (op_disc.upper_ & 0x100000UL) {
    if (op_disc.upper_ & 0x80000UL) {
      if (op_disc.upper_ & 0x40000UL) {
        if (op_disc.upper_ & 0x20000UL) {
          if (my_disc.upper_ & 0x10000UL) {
            count += 4;
          }
        } else if (my_disc.upper_ & 0x20000UL) {
          count += 3;
        }
      } else if (my_disc.upper_ & 0x40000UL) {
        count += 2;
      }
    } else if (my_disc.upper_ & 0x80000UL) {
      count += 1;
    }
  }
  if (op_disc.upper_ & 0x2000UL) {
    if (op_disc.upper_ & 0x20UL) {
      if (op_disc.lower_ & 0x20000000UL) {
        if (op_disc.lower_ & 0x200000UL) {
          if (op_disc.lower_ & 0x2000UL) {
            if (my_disc.lower_ & 0x20UL) {
              count += 5;
            }
          } else if (my_disc.lower_ & 0x2000UL) {
            count += 4;
          }
        } else if (my_disc.lower_ & 0x200000UL) {
          count += 3;
        }
      } else if (my_disc.lower_ & 0x20000000UL) {
        count += 2;
      }
    } else if (my_disc.upper_ & 0x20UL) {
      count += 1;
    }
  }
  if (op_disc.upper_ & 0x4000UL) {
    if (my_disc.upper_ & 0x80UL) {
      count += 1;
    }
  }
  if (op_disc.upper_ & 0x1000UL) {
    if (op_disc.upper_ & 0x8UL) {
      if (op_disc.lower_ & 0x4000000UL) {
        if (op_disc.lower_ & 0x20000UL) {
          if (my_disc.lower_ & 0x100UL) {
            count += 4;
          }
        } else if (my_disc.lower_ & 0x20000UL) {
          count += 3;
        }
      } else if (my_disc.lower_ & 0x4000000UL) {
        count += 2;
      }
    } else if (my_disc.upper_ & 0x8UL) {
      count += 1;
    }
  }
  return count;
}

static int g_66(const bit_matrix& my_disc, const bit_matrix& op_disc) {
  int count = 0;
  if (op_disc.upper_ & 0x200000UL) {
    if (op_disc.upper_ & 0x100000UL) {
      if (op_disc.upper_ & 0x80000UL) {
        if (op_disc.upper_ & 0x40000UL) {
          if (op_disc.upper_ & 0x20000UL) {
            if (my_disc.upper_ & 0x10000UL) {
              count += 5;
            }
          } else if (my_disc.upper_ & 0x20000UL) {
            count += 4;
          }
        } else if (my_disc.upper_ & 0x40000UL) {
          count += 3;
        }
      } else if (my_disc.upper_ & 0x80000UL) {
        count += 2;
      }
    } else if (my_disc.upper_ & 0x100000UL) {
      count += 1;
    }
  }
  if (op_disc.upper_ & 0x4000UL) {
    if (op_disc.upper_ & 0x40UL) {
      if (op_disc.lower_ & 0x40000000UL) {
        if (op_disc.lower_ & 0x400000UL) {
          if (op_disc.lower_ & 0x4000UL) {
            if (my_disc.lower_ & 0x40UL) {
              count += 5;
            }
          } else if (my_disc.lower_ & 0x4000UL) {
            count += 4;
          }
        } else if (my_disc.lower_ & 0x400000UL) {
          count += 3;
        }
      } else if (my_disc.lower_ & 0x40000000UL) {
        count += 2;
      }
    } else if (my_disc.upper_ & 0x40UL) {
      count += 1;
    }
  }
  if (op_disc.upper_ & 0x2000UL) {
    if (op_disc.upper_ & 0x10UL) {
      if (op_disc.lower_ & 0x8000000UL) {
        if (op_disc.lower_ & 0x40000UL) {
          if (op_disc.lower_ & 0x200UL) {
            if (my_disc.lower_ & 0x1UL) {
              count += 5;
            }
          } else if (my_disc.lower_ & 0x200UL) {
            count += 4;
          }
        } else if (my_disc.lower_ & 0x40000UL) {
          count += 3;
        }
      } else if (my_disc.lower_ & 0x8000000UL) {
        count += 2;
      }
    } else if (my_disc.upper_ & 0x10UL) {
      count += 1;
    }
  }
  return count;
}

static int g_67(const bit_matrix& my_disc, const bit_matrix& op_disc) {
  int count = 0;
  if (op_disc.upper_ & 0x400000UL) {
    if (op_disc.upper_ & 0x200000UL) {
      if (op_disc.upper_ & 0x100000UL) {
        if (op_disc.upper_ & 0x80000UL) {
          if (op_disc.upper_ & 0x40000UL) {
            if (op_disc.upper_ & 0x20000UL) {
              if (my_disc.upper_ & 0x10000UL) {
                count += 6;
              }
            } else if (my_disc.upper_ & 0x20000UL) {
              count += 5;
            }
          } else if (my_disc.upper_ & 0x40000UL) {
            count += 4;
          }
        } else if (my_disc.upper_ & 0x80000UL) {
          count += 3;
        }
      } else if (my_disc.upper_ & 0x100000UL) {
        count += 2;
      }
    } else if (my_disc.upper_ & 0x200000UL) {
      count += 1;
    }
  }
  if (op_disc.upper_ & 0x8000UL) {
    if (op_disc.upper_ & 0x80UL) {
      if (op_disc.lower_ & 0x80000000UL) {
        if (op_disc.lower_ & 0x800000UL) {
          if (op_disc.lower_ & 0x8000UL) {
            if (my_disc.lower_ & 0x80UL) {
              count += 5;
            }
          } else if (my_disc.lower_ & 0x8000UL) {
            count += 4;
          }
        } else if (my_disc.lower_ & 0x800000UL) {
          count += 3;
        }
      } else if (my_disc.lower_ & 0x80000000UL) {
        count += 2;
      }
    } else if (my_disc.upper_ & 0x80UL) {
      count += 1;
    }
  }
  if (op_disc.upper_ & 0x4000UL) {
    if (op_disc.upper_ & 0x20UL) {
      if (op_disc.lower_ & 0x10000000UL) {
        if (op_disc.lower_ & 0x80000UL) {
          if (op_disc.lower_ & 0x400UL) {
            if (my_disc.lower_ & 0x2UL) {
              count += 5;
            }
          } else if (my_disc.lower_ & 0x400UL) {
            count += 4;
          }
        } else if (my_disc.lower_ & 0x80000UL) {
          count += 3;
        }
      } else if (my_disc.lower_ & 0x10000000UL) {
        count += 2;
      }
    } else if (my_disc.upper_ & 0x20UL) {
      count += 1;
    }
  }
  return count;
}

static int g_70(const bit_matrix& my_disc, const bit_matrix& op_disc) {
  int count = 0;
  if (op_disc.upper_ & 0x2000000UL) {
    if (op_disc.upper_ & 0x4000000UL) {
      if (op_disc.upper_ & 0x8000000UL) {
        if (op_disc.upper_ & 0x10000000UL) {
          if (op_disc.upper_ & 0x20000000UL) {
            if (op_disc.upper_ & 0x40000000UL) {
              if (my_disc.upper_ & 0x80000000UL) {
                count += 6;
              }
            } else if (my_disc.upper_ & 0x40000000UL) {
              count += 5;
            }
          } else if (my_disc.upper_ & 0x20000000UL) {
            count += 4;
          }
        } else if (my_disc.upper_ & 0x10000000UL) {
          count += 3;
        }
      } else if (my_disc.upper_ & 0x8000000UL) {
        count += 2;
      }
    } else if (my_disc.upper_ & 0x4000000UL) {
      count += 1;
    }
  }
  if (op_disc.upper_ & 0x10000UL) {
    if (op_disc.upper_ & 0x100UL) {
      if (op_disc.upper_ & 0x1UL) {
        if (op_disc.lower_ & 0x1000000UL) {
          if (op_disc.lower_ & 0x10000UL) {
            if (op_disc.lower_ & 0x100UL) {
              if (my_disc.lower_ & 0x1UL) {
                count += 6;
              }
            } else if (my_disc.lower_ & 0x100UL) {
              count += 5;
            }
          } else if (my_disc.lower_ & 0x10000UL) {
            count += 4;
          }
        } else if (my_disc.lower_ & 0x1000000UL) {
          count += 3;
        }
      } else if (my_disc.upper_ & 0x1UL) {
        count += 2;
      }
    } else if (my_disc.upper_ & 0x100UL) {
      count += 1;
    }
  }
  if (op_disc.upper_ & 0x20000UL) {
    if (op_disc.upper_ & 0x400UL) {
      if (op_disc.upper_ & 0x8UL) {
        if (op_disc.lower_ & 0x10000000UL) {
          if (op_disc.lower_ & 0x200000UL) {
            if (op_disc.lower_ & 0x4000UL) {
              if (my_disc.lower_ & 0x80UL) {
                count += 6;
              }
            } else if (my_disc.lower_ & 0x4000UL) {
              count += 5;
            }
          } else if (my_disc.lower_ & 0x200000UL) {
            count += 4;
          }
        } else if (my_disc.lower_ & 0x10000000UL) {
          count += 3;
        }
      } else if (my_disc.upper_ & 0x8UL) {
        count += 2;
      }
    } else if (my_disc.upper_ & 0x400UL) {
      count += 1;
    }
  }
  return count;
}

static int g_71(const bit_matrix& my_disc, const bit_matrix& op_disc) {
  int count = 0;
  if (op_disc.upper_ & 0x4000000UL) {
    if (op_disc.upper_ & 0x8000000UL) {
      if (op_disc.upper_ & 0x10000000UL) {
        if (op_disc.upper_ & 0x20000000UL) {
          if (op_disc.upper_ & 0x40000000UL) {
            if (my_disc.upper_ & 0x80000000UL) {
              count += 5;
            }
          } else if (my_disc.upper_ & 0x40000000UL) {
            count += 4;
          }
        } else if (my_disc.upper_ & 0x20000000UL) {
          count += 3;
        }
      } else if (my_disc.upper_ & 0x10000000UL) {
        count += 2;
      }
    } else if (my_disc.upper_ & 0x8000000UL) {
      count += 1;
    }
  }
  if (op_disc.upper_ & 0x20000UL) {
    if (op_disc.upper_ & 0x200UL) {
      if (op_disc.upper_ & 0x2UL) {
        if (op_disc.lower_ & 0x2000000UL) {
          if (op_disc.lower_ & 0x20000UL) {
            if (op_disc.lower_ & 0x200UL) {
              if (my_disc.lower_ & 0x2UL) {
                count += 6;
              }
            } else if (my_disc.lower_ & 0x200UL) {
              count += 5;
            }
          } else if (my_disc.lower_ & 0x20000UL) {
            count += 4;
          }
        } else if (my_disc.lower_ & 0x2000000UL) {
          count += 3;
        }
      } else if (my_disc.upper_ & 0x2UL) {
        count += 2;
      }
    } else if (my_disc.upper_ & 0x200UL) {
      count += 1;
    }
  }
  if (op_disc.upper_ & 0x40000UL) {
    if (op_disc.upper_ & 0x800UL) {
      if (op_disc.upper_ & 0x10UL) {
        if (op_disc.lower_ & 0x20000000UL) {
          if (op_disc.lower_ & 0x400000UL) {
            if (my_disc.lower_ & 0x8000UL) {
              count += 5;
            }
          } else if (my_disc.lower_ & 0x400000UL) {
            count += 4;
          }
        } else if (my_disc.lower_ & 0x20000000UL) {
          count += 3;
        }
      } else if (my_disc.upper_ & 0x10UL) {
        count += 2;
      }
    } else if (my_disc.upper_ & 0x800UL) {
      count += 1;
    }
  }
  return count;
}

static int g_72(const bit_matrix& my_disc, const bit_matrix& op_disc) {
  int count = 0;
  if (op_disc.upper_ & 0x8000000UL) {
    if (op_disc.upper_ & 0x10000000UL) {
      if (op_disc.upper_ & 0x20000000UL) {
        if (op_disc.upper_ & 0x40000000UL) {
          if (my_disc.upper_ & 0x80000000UL) {
            count += 4;
          }
        } else if (my_disc.upper_ & 0x40000000UL) {
          count += 3;
        }
      } else if (my_disc.upper_ & 0x20000000UL) {
        count += 2;
      }
    } else if (my_disc.upper_ & 0x10000000UL) {
      count += 1;
    }
  }
  if (op_disc.upper_ & 0x2000000UL) {
    if (my_disc.upper_ & 0x1000000UL) {
      count += 1;
    }
  }
  if (op_disc.upper_ & 0x40000UL) {
    if (op_disc.upper_ & 0x400UL) {
      if (op_disc.upper_ & 0x4UL) {
        if (op_disc.lower_ & 0x4000000UL) {
          if (op_disc.lower_ & 0x40000UL) {
            if (op_disc.lower_ & 0x400UL) {
              if (my_disc.lower_ & 0x4UL) {
                count += 6;
              }
            } else if (my_disc.lower_ & 0x400UL) {
              count += 5;
            }
          } else if (my_disc.lower_ & 0x40000UL) {
            count += 4;
          }
        } else if (my_disc.lower_ & 0x4000000UL) {
          count += 3;
        }
      } else if (my_disc.upper_ & 0x4UL) {
        count += 2;
      }
    } else if (my_disc.upper_ & 0x400UL) {
      count += 1;
    }
  }
  if (op_disc.upper_ & 0x80000UL) {
    if (op_disc.upper_ & 0x1000UL) {
      if (op_disc.upper_ & 0x20UL) {
        if (op_disc.lower_ & 0x40000000UL) {
          if (my_disc.lower_ & 0x800000UL) {
            count += 4;
          }
        } else if (my_disc.lower_ & 0x40000000UL) {
          count += 3;
        }
      } else if (my_disc.upper_ & 0x20UL) {
        count += 2;
      }
    } else if (my_disc.upper_ & 0x1000UL) {
      count += 1;
    }
  }
  if (op_disc.upper_ & 0x20000UL) {
    if (my_disc.upper_ & 0x100UL) {
      count += 1;
    }
  }
  return count;
}

static int g_73(const bit_matrix& my_disc, const bit_matrix& op_disc) {
  int count = 0;
  if (op_disc.upper_ & 0x10000000UL) {
    if (op_disc.upper_ & 0x20000000UL) {
      if (op_disc.upper_ & 0x40000000UL) {
        if (my_disc.upper_ & 0x80000000UL) {
          count += 3;
        }
      } else if (my_disc.upper_ & 0x40000000UL) {
        count += 2;
      }
    } else if (my_disc.upper_ & 0x20000000UL) {
      count += 1;
    }
  }
  if (op_disc.upper_ & 0x4000000UL) {
    if (op_disc.upper_ & 0x2000000UL) {
      if (my_disc.upper_ & 0x1000000UL) {
        count += 2;
      }
    } else if (my_disc.upper_ & 0x2000000UL) {
      count += 1;
    }
  }
  if (op_disc.upper_ & 0x80000UL) {
    if (op_disc.upper_ & 0x800UL) {
      if (op_disc.upper_ & 0x8UL) {
        if (op_disc.lower_ & 0x8000000UL) {
          if (op_disc.lower_ & 0x80000UL) {
            if (op_disc.lower_ & 0x800UL) {
              if (my_disc.lower_ & 0x8UL) {
                count += 6;
              }
            } else if (my_disc.lower_ & 0x800UL) {
              count += 5;
            }
          } else if (my_disc.lower_ & 0x80000UL) {
            count += 4;
          }
        } else if (my_disc.lower_ & 0x8000000UL) {
          count += 3;
        }
      } else if (my_disc.upper_ & 0x8UL) {
        count += 2;
      }
    } else if (my_disc.upper_ & 0x800UL) {
      count += 1;
    }
  }
  if (op_disc.upper_ & 0x100000UL) {
    if (op_disc.upper_ & 0x2000UL) {
      if (op_disc.upper_ & 0x40UL) {
        if (my_disc.lower_ & 0x80000000UL) {
          count += 3;
        }
      } else if (my_disc.upper_ & 0x40UL) {
        count += 2;
      }
    } else if (my_disc.upper_ & 0x2000UL) {
      count += 1;
    }
  }
  if (op_disc.upper_ & 0x40000UL) {
    if (op_disc.upper_ & 0x200UL) {
      if (my_disc.upper_ & 0x1UL) {
        count += 2;
      }
    } else if (my_disc.upper_ & 0x200UL) {
      count += 1;
    }
  }
  return count;
}

static int g_74(const bit_matrix& my_disc, const bit_matrix& op_disc) {
  int count = 0;
  if (op_disc.upper_ & 0x20000000UL) {
    if (op_disc.upper_ & 0x40000000UL) {
      if (my_disc.upper_ & 0x80000000UL) {
        count += 2;
      }
    } else if (my_disc.upper_ & 0x40000000UL) {
      count += 1;
    }
  }
  if (op_disc.upper_ & 0x8000000UL) {
    if (op_disc.upper_ & 0x4000000UL) {
      if (op_disc.upper_ & 0x2000000UL) {
        if (my_disc.upper_ & 0x1000000UL) {
          count += 3;
        }
      } else if (my_disc.upper_ & 0x2000000UL) {
        count += 2;
      }
    } else if (my_disc.upper_ & 0x4000000UL) {
      count += 1;
    }
  }
  if (op_disc.upper_ & 0x100000UL) {
    if (op_disc.upper_ & 0x1000UL) {
      if (op_disc.upper_ & 0x10UL) {
        if (op_disc.lower_ & 0x10000000UL) {
          if (op_disc.lower_ & 0x100000UL) {
            if (op_disc.lower_ & 0x1000UL) {
              if (my_disc.lower_ & 0x10UL) {
                count += 6;
              }
            } else if (my_disc.lower_ & 0x1000UL) {
              count += 5;
            }
          } else if (my_disc.lower_ & 0x100000UL) {
            count += 4;
          }
        } else if (my_disc.lower_ & 0x10000000UL) {
          count += 3;
        }
      } else if (my_disc.upper_ & 0x10UL) {
        count += 2;
      }
    } else if (my_disc.upper_ & 0x1000UL) {
      count += 1;
    }
  }
  if (op_disc.upper_ & 0x200000UL) {
    if (op_disc.upper_ & 0x4000UL) {
      if (my_disc.upper_ & 0x80UL) {
        count += 2;
      }
    } else if (my_disc.upper_ & 0x4000UL) {
      count += 1;
    }
  }
  if (op_disc.upper_ & 0x80000UL) {
    if (op_disc.upper_ & 0x400UL) {
      if (op_disc.upper_ & 0x2UL) {
        if (my_disc.lower_ & 0x1000000UL) {
          count += 3;
        }
      } else if (my_disc.upper_ & 0x2UL) {
        count += 2;
      }
    } else if (my_disc.upper_ & 0x400UL) {
      count += 1;
    }
  }
  return count;
}

static int g_75(const bit_matrix& my_disc, const bit_matrix& op_disc) {
  int count = 0;
  if (op_disc.upper_ & 0x40000000UL) {
    if (my_disc.upper_ & 0x80000000UL) {
      count += 1;
    }
  }
  if (op_disc.upper_ & 0x10000000UL) {
    if (op_disc.upper_ & 0x8000000UL) {
      if (op_disc.upper_ & 0x4000000UL) {
        if (op_disc.upper_ & 0x2000000UL) {
          if (my_disc.upper_ & 0x1000000UL) {
            count += 4;
          }
        } else if (my_disc.upper_ & 0x2000000UL) {
          count += 3;
        }
      } else if (my_disc.upper_ & 0x4000000UL) {
        count += 2;
      }
    } else if (my_disc.upper_ & 0x8000000UL) {
      count += 1;
    }
  }
  if (op_disc.upper_ & 0x200000UL) {
    if (op_disc.upper_ & 0x2000UL) {
      if (op_disc.upper_ & 0x20UL) {
        if (op_disc.lower_ & 0x20000000UL) {
          if (op_disc.lower_ & 0x200000UL) {
            if (op_disc.lower_ & 0x2000UL) {
              if (my_disc.lower_ & 0x20UL) {
                count += 6;
              }
            } else if (my_disc.lower_ & 0x2000UL) {
              count += 5;
            }
          } else if (my_disc.lower_ & 0x200000UL) {
            count += 4;
          }
        } else if (my_disc.lower_ & 0x20000000UL) {
          count += 3;
        }
      } else if (my_disc.upper_ & 0x20UL) {
        count += 2;
      }
    } else if (my_disc.upper_ & 0x2000UL) {
      count += 1;
    }
  }
  if (op_disc.upper_ & 0x400000UL) {
    if (my_disc.upper_ & 0x8000UL) {
      count += 1;
    }
  }
  if (op_disc.upper_ & 0x100000UL) {
    if (op_disc.upper_ & 0x800UL) {
      if (op_disc.upper_ & 0x4UL) {
        if (op_disc.lower_ & 0x2000000UL) {
          if (my_disc.lower_ & 0x10000UL) {
            count += 4;
          }
        } else if (my_disc.lower_ & 0x2000000UL) {
          count += 3;
        }
      } else if (my_disc.upper_ & 0x4UL) {
        count += 2;
      }
    } else if (my_disc.upper_ & 0x800UL) {
      count += 1;
    }
  }
  return count;
}

static int g_76(const bit_matrix& my_disc, const bit_matrix& op_disc) {
  int count = 0;
  if (op_disc.upper_ & 0x20000000UL) {
    if (op_disc.upper_ & 0x10000000UL) {
      if (op_disc.upper_ & 0x8000000UL) {
        if (op_disc.upper_ & 0x4000000UL) {
          if (op_disc.upper_ & 0x2000000UL) {
            if (my_disc.upper_ & 0x1000000UL) {
              count += 5;
            }
          } else if (my_disc.upper_ & 0x2000000UL) {
            count += 4;
          }
        } else if (my_disc.upper_ & 0x4000000UL) {
          count += 3;
        }
      } else if (my_disc.upper_ & 0x8000000UL) {
        count += 2;
      }
    } else if (my_disc.upper_ & 0x10000000UL) {
      count += 1;
    }
  }
  if (op_disc.upper_ & 0x400000UL) {
    if (op_disc.upper_ & 0x4000UL) {
      if (op_disc.upper_ & 0x40UL) {
        if (op_disc.lower_ & 0x40000000UL) {
          if (op_disc.lower_ & 0x400000UL) {
            if (op_disc.lower_ & 0x4000UL) {
              if (my_disc.lower_ & 0x40UL) {
                count += 6;
              }
            } else if (my_disc.lower_ & 0x4000UL) {
              count += 5;
            }
          } else if (my_disc.lower_ & 0x400000UL) {
            count += 4;
          }
        } else if (my_disc.lower_ & 0x40000000UL) {
          count += 3;
        }
      } else if (my_disc.upper_ & 0x40UL) {
        count += 2;
      }
    } else if (my_disc.upper_ & 0x4000UL) {
      count += 1;
    }
  }
  if (op_disc.upper_ & 0x200000UL) {
    if (op_disc.upper_ & 0x1000UL) {
      if (op_disc.upper_ & 0x8UL) {
        if (op_disc.lower_ & 0x4000000UL) {
          if (op_disc.lower_ & 0x20000UL) {
            if (my_disc.lower_ & 0x100UL) {
              count += 5;
            }
          } else if (my_disc.lower_ & 0x20000UL) {
            count += 4;
          }
        } else if (my_disc.lower_ & 0x4000000UL) {
          count += 3;
        }
      } else if (my_disc.upper_ & 0x8UL) {
        count += 2;
      }
    } else if (my_disc.upper_ & 0x1000UL) {
      count += 1;
    }
  }
  return count;
}

static int g_77(const bit_matrix& my_disc, const bit_matrix& op_disc) {
  int count = 0;
  if (op_disc.upper_ & 0x40000000UL) {
    if (op_disc.upper_ & 0x20000000UL) {
      if (op_disc.upper_ & 0x10000000UL) {
        if (op_disc.upper_ & 0x8000000UL) {
          if (op_disc.upper_ & 0x4000000UL) {
            if (op_disc.upper_ & 0x2000000UL) {
              if (my_disc.upper_ & 0x1000000UL) {
                count += 6;
              }
            } else if (my_disc.upper_ & 0x2000000UL) {
              count += 5;
            }
          } else if (my_disc.upper_ & 0x4000000UL) {
            count += 4;
          }
        } else if (my_disc.upper_ & 0x8000000UL) {
          count += 3;
        }
      } else if (my_disc.upper_ & 0x10000000UL) {
        count += 2;
      }
    } else if (my_disc.upper_ & 0x20000000UL) {
      count += 1;
    }
  }
  if (op_disc.upper_ & 0x800000UL) {
    if (op_disc.upper_ & 0x8000UL) {
      if (op_disc.upper_ & 0x80UL) {
        if (op_disc.lower_ & 0x80000000UL) {
          if (op_disc.lower_ & 0x800000UL) {
            if (op_disc.lower_ & 0x8000UL) {
              if (my_disc.lower_ & 0x80UL) {
                count += 6;
              }
            } else if (my_disc.lower_ & 0x8000UL) {
              count += 5;
            }
          } else if (my_disc.lower_ & 0x800000UL) {
            count += 4;
          }
        } else if (my_disc.lower_ & 0x80000000UL) {
          count += 3;
        }
      } else if (my_disc.upper_ & 0x80UL) {
        count += 2;
      }
    } else if (my_disc.upper_ & 0x8000UL) {
      count += 1;
    }
  }
  if (op_disc.upper_ & 0x400000UL) {
    if (op_disc.upper_ & 0x2000UL) {
      if (op_disc.upper_ & 0x10UL) {
        if (op_disc.lower_ & 0x8000000UL) {
          if (op_disc.lower_ & 0x40000UL) {
            if (op_disc.lower_ & 0x200UL) {
              if (my_disc.lower_ & 0x1UL) {
                count += 6;
              }
            } else if (my_disc.lower_ & 0x200UL) {
              count += 5;
            }
          } else if (my_disc.lower_ & 0x40000UL) {
            count += 4;
          }
        } else if (my_disc.lower_ & 0x8000000UL) {
          count += 3;
        }
      } else if (my_disc.upper_ & 0x10UL) {
        count += 2;
      }
    } else if (my_disc.upper_ & 0x2000UL) {
      count += 1;
    }
  }
  return count;
}

int (*flip_f[])(bit_matrix&, bit_matrix&) = {
f_00, f_01, f_02, f_03, f_04, f_05, f_06, f_07, 
f_10, f_11, f_12, f_13, f_14, f_15, f_16, f_17, 
f_20, f_21, f_22, f_23, f_24, f_25, f_26, f_27, 
f_30, f_31, f_32, f_33, f_34, f_35, f_36, f_37, 
f_40, f_41, f_42, f_43, f_44, f_45, f_46, f_47, 
f_50, f_51, f_52, f_53, f_54, f_55, f_56, f_57, 
f_60, f_61, f_62, f_63, f_64, f_65, f_66, f_67, 
f_70, f_71, f_72, f_73, f_74, f_75, f_76, f_77, 
};
int (*count_f[])(const bit_matrix&, const bit_matrix&) = {
g_00, g_01, g_02, g_03, g_04, g_05, g_06, g_07, 
g_10, g_11, g_12, g_13, g_14, g_15, g_16, g_17, 
g_20, g_21, g_22, g_23, g_24, g_25, g_26, g_27, 
g_30, g_31, g_32, g_33, g_34, g_35, g_36, g_37, 
g_40, g_41, g_42, g_43, g_44, g_45, g_46, g_47, 
g_50, g_51, g_52, g_53, g_54, g_55, g_56, g_57, 
g_60, g_61, g_62, g_63, g_64, g_65, g_66, g_67, 
g_70, g_71, g_72, g_73, g_74, g_75, g_76, g_77, 
};
