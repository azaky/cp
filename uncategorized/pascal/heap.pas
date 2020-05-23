const
  maxn = 3000000; 

var
  n,num,nheap,i:longint;
  heap:array[1..maxn+5] of longint;
  a:array[1..maxn+5] of int64;

function pop:longint; //delete the least element of the heap
  var
    i,p,c:longint;
  
  begin
    pop:=heap[1];
    i:=nheap;
    dec(nheap);
    p:=1;
    repeat
      c:=2*p;
      if (c<nheap) and (heap[c]>heap[c+1]) then inc(c);
      if (c>nheap) or (heap[i]<=heap[c]) then break;
      heap[p]:=heap[c]; p:=c;
    until false;
    heap[p]:=heap[i];
  end;

procedure push(vi:longint); //insert a new element to the heap
  var
    c,p:longint;
  
  begin
    inc(nheap);
    c:=nheap;
    repeat
      p:=c div 2;
      if (p=0) or (vi>=heap[p]) then break;
      heap[c]:=heap[p]; c:=p;
    until false;
    heap[c]:=vi;
  end;

begin
  //below is the sample of how to use heap - heapsort
  assign(input,'text.txt'); reset(input);
  assign(output,'text.out'); rewrite(output);
  
  readln(n);
  nheap:=0;
  for i:=1 to n do
    begin
      readln(num);
      push(num);
    end;
  for i:=1 to n do a[i]:=pop;
  for i:=1 to n-1 do writeln(a[i]);
  
  close(input);
  close(output);
end.

