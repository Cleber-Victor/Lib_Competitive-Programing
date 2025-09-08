@78A @for( int i = 1; i <= n; i++){
@160 @  for(int j = 1; j <= n; j++){
@EA0 @    if (i== j) distance[i][j] = 0;
@A96 @    else if(adj[i][j]) distance [i][j] = adj[i][j];
@FB5 @    else distance[i][j]=INF;
@F5C @  }
@16F @}
@    @
@5D3 @for(int k =1; k<=n; k++){
@78A @  for( int i = 1; i <= n; i++){
@160 @    for(int j = 1; j <= n; j++){
@353 @      distance[i][j] = min (distance[i][j], distance[i][k]+distance[k][j]);
@408 @    }
@222 @  }
@AF2 @}
