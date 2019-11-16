var app = {
    // Application Constructor
    initialize: function() {
	
	
		var urlOn = "http://192.168.43.10/ledOn";
		var urlOff = "http://192.168.43.10/ledOff";
        
		$("#buttonOn").click(function(){
			
            $.ajax({
                url: urlOn,
                success: handleResponse
            });
			console.log(urlOn);
            
            function handleResponse(){
			}
			
        });
		
		$("#buttonOff").click(function(){
			
            $.ajax({
                url: urlOff,
                success: handleResponse
            });
			console.log(urlOff);
            
            function handleResponse(){
			}
			
        });
    },
};

app.initialize();