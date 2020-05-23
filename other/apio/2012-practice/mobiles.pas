uses math;

var
  n,i,c1,c2,nrose,nnode,ans,minlevel,maxlevel:longint;
  level,idx,tree,ctree:array[0..1 shl 18] of longint;
  leaf,rose,crose:array[0..1 shl 18] of boolean;

procedure compare(v,vc:longint);
  var
    lvl:longint;
    
  begin
    if leaf[v] or (ans<0) then exit;
    if (tree[2*v]=ctree[2*vc]) and (tree[2*v+1]=ctree[2*vc+1]) then
      begin
        if (tree[2*v]<>1 shl (minlevel-level[v]-1)) and (tree[2*v]<>0) then compare(2*v,2*vc);
        if (tree[2*v+1]<>1 shl (minlevel-level[v]-1)) and (tree[2*v+1]<>0) then compare(2*v+1,2*vc+1);
      end
    else if (tree[2*v]=ctree[2*vc+1]) and (tree[2*v+1]=ctree[2*vc]) then
      begin
        inc(ans);
        if (tree[2*v]<>1 shl (minlevel-level[v]-1)) and (tree[2*v]<>0) then compare(2*v,2*vc+1);
        if (tree[2*v+1]<>1 shl (minlevel-level[v]-1)) and (tree[2*v+1]<>0) then compare(2*v+1,2*vc);
      end
    else ans:=-1;
  end;

begin
  readln(n);
  idx[1]:=1; minlevel:=maxlongint; maxlevel:=0; level[1]:=0;
  for i:=1 to n do
    begin
      readln(c1,c2);
      if c1=c2 then
        begin
          minlevel := min(minlevel,level[idx[i]+1]); maxlevel := max(maxlevel,level[idx[i]+1]);
          leaf[2*idx[i]]:=true; leaf[2*idx[i]+1]:=true;
          continue;
        end;
      if c1<0 then
        begin
          leaf[2*idx[i]]:=true;
          minlevel := min(minlevel,level[idx[i]+1]); maxlevel := max(maxlevel,level[idx[i]+1]);
        end
      else idx[c1]:=2*idx[i];
      if c2<0 then
        begin
          leaf[2*idx[i]+1]:=true;
          minlevel := min(minlevel,level[idx[i]+1]); maxlevel := max(maxlevel,level[idx[i]+1]);
        end
      else idx[c2]:=2*idx[i]+1;
    end;
  //check if the difference of the levels is at most 1
  if maxlevel=minlevel then
    begin
      writeln(0);halt;
    end
  else if maxlevel-minlevel>1 then
    begin
      writeln(-1);halt;
    end;
  nnode := (1 shl (minlevel+1))-1;
  //creating roses
  for i:=(nnode+1) div 2 to nnode do
    if not leaf[i] then
      begin
        leaf[i]:=true; leaf[2*i]:=false; leaf[2*i+1]:=false;
        rose[i]:=true; inc(nrose);
      end;
  //creating copy of the tree, which meets brother's requirement
  //the first nrose leaf of the tree must be rose, so
  for i:=(nnode+1) div 2 to ((nnode+1) div 2)+nrose-1 do crose[i]:= true;
  //build the tree as well as the copy of the tree
  for i:=nnode downto 1 do
    if leaf[i] then
      if rose[i] then tree[i]:=1 else tree[i]:=0
    else tree[i]:=tree[2*i]+tree[2*i+1];
  for i:=nnode downto 1 do
    if leaf[i] then
      if crose[i] then ctree[i]:=1 else ctree[i]:=0
    else ctree[i]:=ctree[2*i]+ctree[2*i+1];
  //now, back to the problem
  //compare tree to ctree
  ans:=0; compare(1,1); writeln(ans);
end.
