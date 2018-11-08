int numberOfWays( vector  x, int C )
  {
    vector  a, b;
    int n1 = x.size() / 2, n2 = x.size() - x.size() / 2;
    for (int i = 0; i < (1 << n1); i++)
    {
      a.push_back(0);
      for (int j = 0; j < n1; j++)
        if ((i >> j) & 1)
          a[a.size() - 1] += x[j];
    }
    for (int i = 0; i < (1 << n2); i++)
    {
      b.push_back(0);
      for (int j = 0; j < n2; j++)
        if ((i >> j) & 1)
          b[b.size() - 1] += x[n1 + j];
    }
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    fprintf(stderr, "a.size()=%d b.size()=%d", a.size(), b.size());
    int ans = 0;
    for (int i = 0; i < a.size(); i++)
    {
      int mi = 0, ma = b.size() - 1, av;
      while (mi < ma)
      {
        av = (mi + ma + 1) / 2;
        if (b[av] + a[i] <= C)
          mi = av;
        else
          ma = av - 1;
      }
      if (a[i] <= C)
        ans += mi + 1;
    }
    return ans;
  }
