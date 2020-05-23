const
  maxn = 1000000;

var
  n,i,j,queue_top,queue_bottom,max_top,max_bottom:longint;
  x:int64;
  max:array[0..maxn] of longint;
  queue:array[0..maxn] of int64;
  task:string[7];

begin
  readln(n);
  queue_top:=0; queue_bottom:=0; max_top:=0; max_bottom:=1;
  for i:=1 to n do
    begin
	  read(task);
	  if task = 'ENQUEUE' then
	    begin
		  read(x);
		  //enqueueing the input into the queue table
		  inc(queue_top); queue[queue_top]:=x;
		  //stacking the input into the max table
		  //if the table is currently empty
		  if max_top<max_bottom then
		    begin
			  inc(max_top);
			  max[max_top]:=queue_top;
			end
		  //else if current value is higher than all the values before
		  else if x>=queue[max[max_bottom]] then
		    begin
			  max_top:=max_bottom;
			  max[max_top]:=queue_top;
			end
		  //otherwise just find the appropiate place for stacking current value
		  else
		    begin
			  inc(max_top);
			  while queue[max[max_top-1]]<=x do dec(max_top);
			  max[max_top]:=queue_top;
			end;
		end
	  else if task = 'DEQUEUE' then
	    begin
		  //dequeueing
		  if queue_top=queue_bottom then writeln('DATA IS EMPTY')
		    else
			  begin
			    inc(queue_bottom);
				writeln(queue[queue_bottom]);
				//check if the current max is dequeued
				//if so, pop it out
				if max[max_bottom]=queue_bottom then inc(max_bottom);
			  end;
		end
	  else if task = 'FINDMAX' then
	    begin
		  //print the current largest value
		  if max_top<max_bottom then writeln('DATA IS EMPTY')
		    else writeln(queue[max[max_bottom]]);
		end;
	  readln;
	end;
end.
