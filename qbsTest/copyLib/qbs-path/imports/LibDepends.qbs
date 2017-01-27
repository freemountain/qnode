import qbs 1.0

Depends {
  condition: {
    print(product.name,"depends: ", name);

    return true;
  }


}
