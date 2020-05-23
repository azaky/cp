def solve(N, M, edge_list, start, end):
    # Initialization of an adjacency matrix.
    infinity = 1234567890
    edges = [ [ infinity for j in range(N) ] for i in range(N) ]
    for i in range(N):
        edges[i][i] = 0

    # Entering edge lengths into the adjacency matrix.
    for edge in edge_list:
        u, v, w = edge
        edges[u][v] = edges[v][u] = w

    for i in range(N):
        for j in range(N):
            for k in range(N):
                edges[i][j] = min(edges[i][j], edges[i][k] + edges[k][j])
    return edges[start][end]
