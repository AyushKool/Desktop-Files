library(shiny)
library(shinythemes)
library(ggplot2)
library(plotly)

#https://data.humdata.org/dataset/novel-coronavirus-2019-ncov-cases

deaths <-
  read.csv('C:/Users/ayush/Desktop/R/covid19_deaths.csv', check.names = F)
death <- deaths[deaths$Country == "China", ]
death <- as.data.frame(t(as.matrix(death)))
death <- as.data.frame(death[-1, ])
names(death)[names(death) == 'death[-1, ]'] <- 'y'


confirmed <-
  read.csv('C:/Users/ayush/Desktop/R/covid19_confirmed.csv', check.names = F)
confirm <- confirmed[confirmed$Country == "China", ]
confirm <- as.data.frame(t(as.matrix(confirm)))
confirm <- as.data.frame(confirm[-1, ])
names(confirm)[names(confirm) == 'confirm[-1, ]'] <- 'y'

recovered <-
  read.csv('C:/Users/ayush/Desktop/R/covid19_recovered.csv', check.names = F)
recover <- recovered[recovered$Country == "China", ]
recover <- as.data.frame(t(as.matrix(recover)))
recover <- as.data.frame(recover[-1, ])
names(recover)[names(recover) == 'recover[-1, ]'] <- 'y'


ui <- fluidPage(
  shinythemes::themeSelector(),
  
  h1('Covid-19 Stats (Global)'),
  
  sidebarPanel(
    selectInput('country',
                'Select a Country',
                deaths$Country,
                selected = 'China')
  ),
  mainPanel(plotlyOutput('plot'))
)

server <- function(input, output) {
  death <- reactive({
    tmp <- deaths[deaths$Country == input$country, ]
    tmp <- as.data.frame(t(as.matrix(tmp)))
    tmp <- as.data.frame(tmp[-1, ])
    names(tmp)[names(tmp) == 'tmp[-1, ]'] <- 'y'
    tmp
  })
  
  confirm <- reactive({
    tmp <- confirmed[confirmed$Country == input$country, ]
    tmp <- as.data.frame(t(as.matrix(tmp)))
    tmp <- as.data.frame(tmp[-1, ])
    names(tmp)[names(tmp) == 'tmp[-1, ]'] <- 'y'
    tmp
  })
  
  recover <- reactive({
    tmp <- recovered[recovered$Country == input$country, ]
    tmp <- as.data.frame(t(as.matrix(tmp)))
    tmp <- as.data.frame(tmp[-1, ])
    names(tmp)[names(tmp) == 'tmp[-1, ]'] <- 'y'
    tmp
  })
  
  output$plot <- renderPlotly({
    death <- death()
    confirm <- confirm()
    recover <- recover()
    p <-
      ggplot() +
      
      geom_line(
        data = death,
        aes(
          x = as.Date(row.names(death), format = "%m/%d/%y"),
          y = as.numeric(as.character(y)),
          group = 1
        ),
        linetype = "dashed",
        color = 'red'
      ) +
      
      geom_point(data = death,
                 aes(
                   x = as.Date(row.names(death), format = "%m/%d/%y"),
                   y = as.numeric(as.character(y)),
                   group = 1,
                   text = paste('Date: ',
                                format(
                                  as.Date(row.names(death),
                                          format = "%m/%d/%y"), "%m/%d/%y"
                                ),
                                '\nDeaths: ', y)
                 )) +
      
      geom_line(
        data = confirm,
        aes(
          x = as.Date(row.names(confirm), format = "%m/%d/%y"),
          y = as.numeric(as.character(y)),
          group = 1
        ),
        linetype = "dashed",
        color = 'green'
      ) +
      
      geom_point(data = confirm,
                 aes(
                   x = as.Date(row.names(confirm), format = "%m/%d/%y"),
                   y = as.numeric(as.character(y)),
                   group = 1,
                   text = paste(
                     'Date: ',
                     format(as.Date(row.names(confirm),
                                    format = "%m/%d/%y"), "%m/%d/%y"),
                     '\nConfirmed Cases: ',
                     y
                   )
                 )) +
      
      
      geom_line(
        data = recover,
        aes(
          x = as.Date(row.names(recover), format = "%m/%d/%y"),
          y = as.numeric(as.character(y)),
          group = 1
        ),
        linetype = "dashed",
        color = 'blue'
      ) +
      
      geom_point(data = recover,
                 aes(
                   x = as.Date(row.names(recover), format = "%m/%d/%y"),
                   y = as.numeric(as.character(y)),
                   group = 1,
                   text = paste('Date: ',
                                format(
                                  as.Date(row.names(recover),
                                          format = "%m/%d/%y"), "%m/%d/%y"
                                ),
                                '\nRecovered: ', y)
                 )) +
      
      
      ggtitle(paste("Covid-19 Stats in",
                    input$country)) +
      
      theme(plot.title = element_text(hjust = 0.5)) +
      
      scale_x_date("Time period (2020)",
                   date_labels = '%b') +
      
      ylab("People")
    
    ggplotly(p, tooltip = c("text"))
  })
  
}

shinyApp(ui, server)