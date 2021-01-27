library(shiny)
library(shinythemes)

ui <- fluidPage(
  #shinythemes::themeSelector(),
  
  theme = shinytheme('slate'),
  
  h1('Covid-19 Confirmed Deaths (Global) using Shiny in R'),
  
  sidebarPanel(
    selectInput(
      'country',
      'Select a Country',
      c('Japan', 'China', 'USA'),
      selected = 'Japan'
    ),
    
    dateInput(
      'date',
      label = 'Select a Date',
      value = as.character(as.Date('05/10/20', '%m/%d/%y')),
      min = as.Date('01/22/20', '%m/%d/%y'),
      max = as.Date('05/10/20', '%m/%d/%y'),
      format = 'mm/dd/yy',
      startview = 'month',
      weekstart = 1
    ),
    
    actionButton('reset', 'Reset'),
    
    actionButton('plot', 'Plot', class = 'btn-primary')
    
  ),
  mainPanel(
    
    verbatimTextOutput('dateText', placeholder = TRUE)
  )
)

server <- function(input, output) {
  
  output$dateText <- renderText({
    as.character(input$date)
  })
  
}


shinyApp(ui, server)